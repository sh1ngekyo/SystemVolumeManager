#include "pch.h"
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include "volume.h"

extern "C"
{
	__declspec(dllexport) Volume::f32 GetSystemVolume(Volume::Unit vUnit) {
		CoInitialize(NULL);

		IMMDeviceEnumerator* deviceEnumerator = NULL;
		HRESULT hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
		IMMDevice* defaultDevice = NULL;

		hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
		deviceEnumerator->Release();
		deviceEnumerator = NULL;

		IAudioEndpointVolume* endpointVolume = NULL;
		hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
		defaultDevice->Release();
		defaultDevice = NULL;

		Volume::f32 currentVolume = 0;

		if (vUnit == Volume::Unit::Decibel) {
			hr = endpointVolume->GetMasterVolumeLevel(&currentVolume);
		}

		else if (vUnit == Volume::Unit::Scalar) {
			hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
		}

		endpointVolume->Release();
		CoUninitialize();

		return currentVolume;
	}

	__declspec(dllexport) void MuteUnmute() {
		CoInitialize(NULL);

		IMMDeviceEnumerator* deviceEnumerator = NULL;
		HRESULT hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
		IMMDevice* defaultDevice = NULL;

		hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
		deviceEnumerator->Release();
		deviceEnumerator = NULL;

		IAudioEndpointVolume* endpointVolume = NULL;
		hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
		defaultDevice->Release();
		defaultDevice = NULL;

		static BOOL muted;

		endpointVolume->GetMute(&muted);

		hr = endpointVolume->SetMute(!muted, NULL);

		endpointVolume->Release();
		CoUninitialize();
	}

	__declspec(dllexport) void SetSystemVolume(Volume::f32 value, Volume::Unit type) {
		CoInitialize(NULL);

		IMMDeviceEnumerator* deviceEnumerator = NULL;
		HRESULT hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
		IMMDevice* defaultDevice = NULL;

		hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
		deviceEnumerator->Release();
		deviceEnumerator = NULL;

		IAudioEndpointVolume* endpointVolume = NULL;
		hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
		defaultDevice->Release();
		defaultDevice = NULL;

		if (type == Volume::Unit::Decibel) {
			hr = endpointVolume->SetMasterVolumeLevel(value, NULL);
		}
		else if (type == Volume::Unit::Scalar) {
			hr = endpointVolume->SetMasterVolumeLevelScalar(value, NULL);
		}

		endpointVolume->Release();
		CoUninitialize();
	}
}