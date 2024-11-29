#ifndef __IUBERURF_INTERFACE_DEFINED__
#define __IUBERURF_INTERFACE_DEFINED__

#include "unknwn.h"


#define		UW_STATUS_IN_USE				0	// ������������
#define		UW_STATUS_READY					1	// ����������
#define		UW_STATUS_NOT_CONNECTED			2	// �� ����������
#define		UW_STATUS_TIMER_ERROR			3	// ������ �������� �������
#define		UW_STATUS_UNSUPPORTED_PROTOCOL	4	// ������: ���������� ����������� ����� ��������� ������ ���������������

#define    UW_SIT_LEFT  		0x200 	// ������� � �����
#define    UW_SIT_RIGHT  		0x002 	// ������� � ������
#define    UW_BACK_LOW_LEFT		0x400	// ��� ����� � �����
#define    UW_BACK_LOW_RIGHT	0x004	// ��� ����� � ������
#define    UW_BACK_MID_LEFT		0x800	// �������� ����� � �����
#define    UW_BACK_MID_RIGHT	0x008	// �������� ����� � ������
#define    UW_LEFT				0xE00	// ����� ������� �������
#define    UW_RIGHT				0x00E	// ������ ������� �������
#define    UW_SIT				0x202	// �������
#define    UW_BACK_LOW			0x404	// ��� �����
#define    UW_BACK_MID			0x808	// �������� �����
#define    UW_ALL_ZONES			0xE0E	// ��� ����

// FLE - FILE LOAD ERROR
#define		UW_FLE_NO_ERROR				0	// ��� ������ �������� ������� �� ����� XML
#define		UW_FLE_XML					1	// ������ ��� �������� ������� �� ����� XML
#define		UW_FLE_FILE_OPEN			2	// �� ������� ������� ����
#define		UW_FLE_XML_PARSE			3	// ������ ������� XML
#define		UW_FLE_XML_ELEMENT_NAME		4	// ������ � ������ �������� XML
#define		UW_FLE_XML_ELEMENT_VALUE	5	// ������ �� ��������� �������� XML
#define		UW_FLE_XML_ATTRIBUTE		6	// ������ � ��������� XML
#define		UW_FLE_XML_EMPTY_TAG		7	// ������ ���
#define		UW_FLE_XML_CLOSING_TAG		8	// �� ������ ����������� ���
#define		UW_FLE_XML_TAG_DEFINITION	9	// ������ � ����������� ����
#define		UW_FLE_XML_COMMENT			10	// ������ � ������������
#define		UW_FLE_XML_DECLARATION		11	// ������ � ���������� XML-���������
#define		UW_FLE_XML_EMPTY_DOCUMENT	12	// ������ XML ��������
#define		UW_FLE_XML_EOF_OR_NULL		13	// ������ ����� ����� ��� �������� �������
#define		UW_FLE_XML_CDATA			14	// ������ ������ CDATA

#define		UW_FLE_PATH_CHAR_CONVERSION		50	// ������ �������������� ��������� ���� � ������������ ������
#define		UW_FLE_ROOT						51	// �������� �������� ������� (�� 'uberwoorf_vibro_effect')
#define		UW_FLE_ZONES_MISSING			52	// ������� �������� �� ������
#define		UW_FLE_ZONES_INCORRECT			53	// �������� �������� �������� �� ����������
#define		UW_FLE_VPOINT_INCORRECT			54	// ������� ����� �������� �� ���������
#define		UW_FLE_VPOINT_NOT_UNIQUE		55	// ������� ����� �������� �� ��������
#define		UW_FLE_AMPL_TIME_MISSING		56	// ������� ��������� �/��� ������� �� ������
#define		UW_FLE_AMPL_TIME_INCORRECT		57	// �������� �������� ��������� �/��� ������� �� ����������
#define		UW_FLE_VPOINT_UNKNOWN_TAG		58	// ����������� ��� � �������� ����� ��������
#define		UW_FLE_VPOINT_MISSING			59	// ������� ����� �� ����� �������� �� ������
#define		UW_FLE_VIBRATION_UNKNOWN_TAG	60	// ����������� ��� � �������� ��������
#define		UW_FLE_NO_VIBRATIONS			61	// ������ �� �������� ��������
#define		UW_FLE_EFFECT_NOT_FOUND			62	// ������ � ����� ������������ �� ������
#define		UW_FLE_EFFECT_ZERO_LENGTH		63	// ������ ����� ������� ������������

#define		UW_VALIDATION_NO_ERROR								0	// ��� ������ �������� ��������
#define		UW_VALIDATION_FAILURE								80	// ������ (exception) � �������� �������� ��������
#define		UW_VALIDATION_NO_ZONES								81	// ��� �������� �� ������� �� ����� ���������
#define		UW_VALIDATION_ZERO_LENGTH							82	// ������� ������������ ��������
#define		UW_VALIDATION_LESS_THAN_2_POINTS_OR_1_INFINITE		83	// ������ ���� ������� 2 ����� ��������, ��� 1 �� �������� �������������
#define		UW_VALIDATION_INFINITY_NOT_LAST_OR_SINGLE			84	// ������������� ����� ���� ��������� ��� ������������ �������� �������
#define		UW_VALIDATION_INFINITY_AMPLITUDE_NOT_AS_PREVIOUS	85	// ���� ������������� ����, �� ��������� ������ ���� ����� ��, ��� �� ���������� �������
#define		UW_VALIDATION_INFINITY_AMPLITUDE_ZERO				86	// ��������� � ����������� �������� �������
#define		UW_VALIDATION_NEXT_TIME_NOT_EQUAL_OR_MORE			87	// ����������� ������� ������ ���� ������ ���������� ��� ������ ��
#define		UW_VALIDATION_THREE_OR_MORE_EQUAL_TIMES				88	// �� ����������� ������ ��� � ����� ���������� ������� �������
#define		UW_VALIDATION_TIME_OUT_OF_RANGE						89	// ����� ��� ��������� (0... 1 000 000 ��)

#define		UW_LANG_RUSSIAN		0x0419		// ��� �������� ����� 



struct IUberwoorf : public IUnknown
{
public:
	virtual HRESULT STDMETHODCALLTYPE uwGetApiVersion(UINT *version) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwGetStatus(UINT *status) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwGetSerialNumber(char *serialBuffer, UINT serialBufferSize) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwOpen(UINT *status) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwReset() = 0;
	virtual HRESULT STDMETHODCALLTYPE uwSetGain(UINT gain) = 0;	
	virtual HRESULT STDMETHODCALLTYPE uwCreateEffect(UINT *effectHandle) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwSetSimpleVibration(UINT effectHandle, UINT zones, 
		UINT startDelay, UINT duration, BYTE amplitude, UINT *vibrationHandle) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwSetVibration(UINT effectHandle, UINT zones, 
		UINT *durations, BYTE *amplitudes, UINT count, UINT *vibrationHandle) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwStartEffect(UINT effectHandle, UINT count) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwStopEffect(UINT effectHandle) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwPauseEffect(UINT effectHandle) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwResumeEffect(UINT effectHandle) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwUpdateSimpleVibration(UINT effectHandle, UINT vibrationHandle, 
		UINT zones, UINT startDelay, UINT duration, BYTE amplitude) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwUpdateVibration(UINT effectHandle, UINT vibrationHandle,
		UINT zones, UINT *durations, BYTE *amplitudes, UINT count) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwUpdateEffectAmplitudes(UINT effectHandle, UINT coefficient) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwDeleteEffectVibration(UINT vibrationHandle) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwDeleteEffect(UINT effectHandle) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwClose() = 0;
	virtual HRESULT STDMETHODCALLTYPE uwLoadEffectFromFile(UINT effectHandle, 
		const wchar_t *effectFilePath, UINT *errorCode) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwGetEffectLength(UINT effectHandle, UINT *nonInifinitePartMs, bool *isInfinite) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwValidateVibration(UINT *validationResult, UINT zones, UINT count,
		UINT *durations, BYTE *amplitudes) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwGetErrorDescriptionByCode(UINT errorCode, UINT languageCode, wchar_t *errDescr) = 0;

	virtual HRESULT STDMETHODCALLTYPE uwGetEffectInfo(UINT effectHandle, UINT *gain, UINT *vibrationCount) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwGetEffectVibrations(UINT effectHandle, UINT *vibrationCount, UINT *vibrationHandles) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwGetVibrationInfo(UINT vibrationHandle, UINT *zones, UINT *vibrationPointCount) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwGetVibrationPoints(UINT vibrationHandle, UINT *vibrationPointCount, UINT *durationPoints, BYTE *amplitudes) = 0;

	virtual HRESULT STDMETHODCALLTYPE uwCloneEffect(UINT effectHandle, UINT *clonedEffectHandle) = 0;

	virtual HRESULT STDMETHODCALLTYPE uwSetEffectGain(UINT effectHandle, UINT effectGain) = 0;

	virtual HRESULT STDMETHODCALLTYPE uwSetVibrationEx(UINT effectHandle, UINT zones, UINT looped,
		UINT *durations, BYTE *amplitudes, UINT count, UINT *vibrationHandle) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwGetVibrationInfoEx(UINT vibrationHandle, UINT *zones, UINT *looped, UINT *vibrationPointCount) = 0;
	virtual HRESULT STDMETHODCALLTYPE uwLoadEffectFromString(UINT effectHandle, const char *content, UINT *errorCode) = 0;
};

// {0AC11AE4-C1F7-4fa8-B85B-3789EDAA583A}
DEFINE_GUID(IID_IUberwoorf, 0xac11ae4, 0xc1f7, 0x4fa8, 0xb8, 0x5b, 0x37, 0x89, 0xed, 0xaa, 0x58, 0x3a);

// {22420DBA-2927-4d71-B6B8-028982A62B72}
DEFINE_GUID(CLSID_Uberwoorf, 0x22420dba, 0x2927, 0x4d71, 0xb6, 0xb8, 0x2, 0x89, 0x82, 0xa6, 0x2b, 0x72);

    
#endif 	// __IUBERURF_INTERFACE_DEFINED__ 



