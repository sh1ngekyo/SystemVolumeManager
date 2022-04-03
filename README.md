# SystemVolumeManager

A simple Windows library for sound management.

I created the library to use it for c# projects, but it can be used with any other languages.

Example for c#:
```js
/*Get current volume level in %*/
SystemVolumeManager.GetSystemVolume(SystemVolumeManager.VolumeUnit.Scalar);

/*Get current volume level in db*/
SystemVolumeManager.GetSystemVolume(SystemVolumeManager.VolumeUnit.Decibel);

/*Mute if volume unmuted else unmute*/
SystemVolumeManager.MuteUnmute();

/*Set volume level to 10%*/
SystemVolumeManager.SetSystemVolume(0.1f, SystemVolumeManager.VolumeUnit.Scalar);

/*Set volume level to 51% in db*/
SystemVolumeManager.SetSystemVolume(-10f, SystemVolumeManager.VolumeUnit.Decibel);
```
Make sure that the build of projects with the same architecture and the library are connected.