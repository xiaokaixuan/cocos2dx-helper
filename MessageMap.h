#ifndef __MESSAGE_MAP_H__
#define __MESSAGE_MAP_H__


struct tagMSG_FUNC;


#define DECLARE_LAYER_MSG_MAP() virtual tagMSG_FUNC* GetMessageMap();

#define BEGIN_LAYER_MSG_MAP(className)					\
		tagMSG_FUNC* className::GetMessageMap()			\
		{												\
			static tagMSG_FUNC messageMap[] = {

#define ON_LAYER_MESSAGE(uMsg, FuncName) {uMsg, (static_cast<int (CMessageSink::*)(int, int)>(FuncName))},

#define END_LAYER_MSG_MAP()								\
			{0, 0}							};			\
			return messageMap;							\
		}


struct CMessageSink
{
public:
	DECLARE_LAYER_MSG_MAP()

public:
	int OnMsgProc(unsigned int uMsg, int wParam, int lParam);
	int SendMessage(unsigned int uMsg, int wParam, int lParam);
};

struct tagMSG_FUNC
{
	unsigned int uMsg;
	int (CMessageSink::*pFunc)(int, int);
};


inline tagMSG_FUNC* CMessageSink::GetMessageMap()
{
	static tagMSG_FUNC messageMap[] = { {0, 0} };
	return messageMap;
}

inline int CMessageSink::OnMsgProc(unsigned int uMsg, int wParam, int lParam)
{
	tagMSG_FUNC* pMsgFunc = GetMessageMap();
	for (; pMsgFunc->uMsg; ++pMsgFunc)
	{
		if (pMsgFunc->uMsg == uMsg)
		{
			return (this->*pMsgFunc->pFunc)(wParam, lParam);
		}
	}
	return 0;
}

inline int CMessageSink::SendMessage(unsigned int uMsg, int wParam, int lParam)
{
	return OnMsgProc(uMsg, wParam, lParam);
}


#endif // __MESSAGE_MAP_H__


