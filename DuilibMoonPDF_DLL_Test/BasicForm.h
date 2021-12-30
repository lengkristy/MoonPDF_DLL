#pragma once
class BasicForm : public ui::WindowImplBase
{
public:
	BasicForm();
	~BasicForm();

	/**
	* һ�������ӿ��Ǳ���Ҫ��д�Ľӿڣ����������������ӿ�����������
	* GetSkinFolder		�ӿ�������Ҫ���ƵĴ���Ƥ����Դ·��
	* GetSkinFile			�ӿ�������Ҫ���ƵĴ��ڵ� xml �����ļ�
	* GetWindowClassName	�ӿ����ô���Ψһ��������
	*/
	virtual std::wstring GetSkinFolder() override;
	virtual std::wstring GetSkinFile() override;
	virtual std::wstring GetWindowClassName() const override;

	/**
	* �յ� WM_CREATE ��Ϣʱ�ú����ᱻ���ã�ͨ����һЩ�ؼ���ʼ���Ĳ���
	*/
	virtual void InitWindow() override;

	/**
	* �յ� WM_CLOSE ��Ϣʱ�ú����ᱻ����
	*/
	virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	static const std::wstring kClassName;

	/**
	* ���ݿؼ����������Զ���ؼ�
	* @param[in] pstrClass �ؼ�����
	* @return Control* �����Ŀؼ���ָ��
	*/
	virtual ui::Control* CreateControl(const std::wstring& pstrClass) override;

private:
	ui::Button* m_pBtnMax;

private:
	/**
	* ���������ڵ����˵���ť�ĵ�����Ϣ
	* @param[in] msg ��Ϣ�������Ϣ
	* @return bool true �������ݿؼ���Ϣ��false ֹͣ���ݿؼ���Ϣ
	*/
	bool MainMenuButtonClick(ui::EventArgs* param);
};