#include "MoonPDFLoader.h"
#include "../GlobalDefine.h"

int InitMoonPDFEnvironment()
{
	if (g_moonPdfCtx == NULL)
	{
		g_moonPdfCtx = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);
		if (!g_moonPdfCtx)
		{
			return -1;
		}
	}
	return 0;
}

void DestoryMoonPDFEnvironment()
{
	if (g_moonPdfCtx != NULL)
	{
		fz_drop_context(g_moonPdfCtx);
		g_moonPdfCtx = NULL;
	}
}