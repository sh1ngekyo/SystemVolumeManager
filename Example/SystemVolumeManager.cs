using System.Runtime.InteropServices;

namespace Example
{
    public static class SystemVolumeManager
    {
        public enum VolumeUnit
        {
            Decibel,
            Scalar
        }

        [DllImport("SystemVolumeManager")]
        public static extern float GetSystemVolume(VolumeUnit type);

        [DllImport("SystemVolumeManager")]
        public static extern void SetSystemVolume(double value, VolumeUnit type);

        [DllImport("SystemVolumeManager")]
        public static extern void MuteUnmute();
    }
}
