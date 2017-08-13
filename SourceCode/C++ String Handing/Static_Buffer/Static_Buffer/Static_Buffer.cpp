// Static_Buffer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#pragma comment(lib, "winmm.lib")
#include "WaveFile.h"
#include   <iostream> 
using   namespace   std; 

int _tmain(int argc, _TCHAR* argv[])
{
	
	LPDIRECTSOUNDBUFFER8 g_pDSBuffer8 = NULL; //buffer
	LPDIRECTSOUND8 g_pDsd = NULL; //dsound
	CWaveFile *g_pWaveFile= NULL;
	//�����ʼ��DirectSound������
	HRESULT hr;
	if(FAILED(hr = DirectSoundCreate8(NULL,&g_pDsd,NULL)))
	{ 
		return  FALSE;
	}
	 //�����豸��Э����
	HWND m_hWnd = GetConsoleWindow();
	if(FAILED(hr = g_pDsd->SetCooperativeLevel(m_hWnd,DSSCL_PRIORITY)))
	{
		return  FALSE;
	}
	g_pWaveFile = new CWaveFile;
	g_pWaveFile->Open(_T("d:\\test.wav"),NULL,WAVEFILE_READ);
	DSBUFFERDESC dsbd;
	ZeroMemory( &dsbd, sizeof(DSBUFFERDESC) );
	dsbd.dwSize = sizeof(DSBUFFERDESC);
	dsbd.dwFlags = DSBCAPS_GLOBALFOCUS | DSBCAPS_CTRLFX| DSBCAPS_CTRLPOSITIONNOTIFY |DSBCAPS_GETCURRENTPOSITION2;
	dsbd.dwBufferBytes = g_pWaveFile->GetSize();//MAX_AUDIO_BUF * BUFFERNOTIFYSIZE ; 
	dsbd.lpwfxFormat = g_pWaveFile->m_pwfx;
	LPDIRECTSOUNDBUFFER lpbuffer;
	//������������������
	if(FAILED(hr = g_pDsd->CreateSoundBuffer(&dsbd,&lpbuffer,NULL)))
	{
		return  FALSE;
	}
	if( FAILED( hr = lpbuffer->QueryInterface( IID_IDirectSoundBuffer8, (LPVOID*) &g_pDSBuffer8) ) )
    {
		return  FALSE;
	}
	lpbuffer->Release();
	//׼�����������ˣ�����Ϳ�ʼ������
	LPVOID lplockbuf;
	DWORD len;
	DWORD dwWrite;

	g_pDSBuffer8->Lock(0,0,&lplockbuf,&len,NULL,NULL,DSBLOCK_ENTIREBUFFER);
	g_pWaveFile->Read((BYTE*)lplockbuf,len,&dwWrite);
	g_pDSBuffer8->Unlock(lplockbuf,len,NULL,0);
	g_pDSBuffer8->SetCurrentPosition(0);
	g_pDSBuffer8->Play(0,0,DSBPLAY_LOOPING);
}

