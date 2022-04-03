using System;

namespace Example
{
    class Program
    {
        private static void Main(string[] args)
        {
            //Get volume level in %
            Console.WriteLine(SystemVolumeManager.GetSystemVolume(SystemVolumeManager.VolumeUnit.Scalar));
            //Get volume level in db
            Console.WriteLine(SystemVolumeManager.GetSystemVolume(SystemVolumeManager.VolumeUnit.Decibel));
            Console.ReadLine();

            //mute if volume unmuted else unmute;
            SystemVolumeManager.MuteUnmute();
            Console.ReadLine();
            //unmute if volume muted else mute;
            SystemVolumeManager.MuteUnmute();
            Console.ReadLine();

            //set volume level to 10%
            SystemVolumeManager.SetSystemVolume(0.1f, SystemVolumeManager.VolumeUnit.Scalar);
            Console.ReadLine();

            //set volume level to 100%
            SystemVolumeManager.SetSystemVolume(1f, SystemVolumeManager.VolumeUnit.Scalar);
            Console.ReadLine();
        }
    }
}
