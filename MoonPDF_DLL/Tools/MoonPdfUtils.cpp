#include "MoonPdfUtils.h"

void PageMerge(fz_context *ctx, pdf_document * doc_src, pdf_document *doc_des, int page_from, int page_to, pdf_graft_map *graft_map)
{
	pdf_obj *page_ref;
	pdf_obj *page_dict = NULL;
	pdf_obj *obj;
	pdf_obj *ref = NULL;
	int i;

	/* Copy as few key/value pairs as we can. Do not include items that reference other pages. */
	static pdf_obj * const copy_list[] = {
		PDF_NAME(Contents),
		PDF_NAME(Resources),
		PDF_NAME(MediaBox),
		PDF_NAME(CropBox),
		PDF_NAME(BleedBox),
		PDF_NAME(TrimBox),
		PDF_NAME(ArtBox),
		PDF_NAME(Rotate),
		PDF_NAME(UserUnit)
	};

	fz_var(ref);
	fz_var(page_dict);

	fz_try(ctx)
	{
		page_ref = pdf_lookup_page_obj(ctx, doc_src, page_from - 1);
		pdf_flatten_inheritable_page_items(ctx, page_ref);

		/* Make a new page object dictionary to hold the items we copy from the source page. */
		page_dict = pdf_new_dict(ctx, doc_des, 4);

		pdf_dict_put(ctx, page_dict, PDF_NAME(Type), PDF_NAME(Page));

		for (i = 0; i < nelem(copy_list); i++)
		{
			obj = pdf_dict_get(ctx, page_ref, copy_list[i]);
			if (obj != NULL)
				pdf_dict_put_drop(ctx, page_dict, copy_list[i], pdf_graft_mapped_object(ctx, graft_map, obj));
		}

		/* Add the page object to the destination document. */
		ref = pdf_add_object(ctx, doc_des, page_dict);

		/* Insert it into the page tree. */
		pdf_insert_page(ctx, doc_des, page_to - 1, ref);
	}
	fz_always(ctx)
	{
		pdf_drop_obj(ctx, page_dict);
		pdf_drop_obj(ctx, ref);
	}
	fz_catch(ctx)
	{
		fz_rethrow(ctx);
	}
}