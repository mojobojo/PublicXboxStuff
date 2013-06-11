using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MojosLibs.Binary
{
    class BinaryScanner
    {
        public BinaryScanner()
        {
        }

        public delegate void ProgressUpdateCallback(int Percentage);

        private static bool BComp(byte[] A, int Position, byte[] B)
        {
            for (int i = 0; i < B.Length; i++)
            {
                if (A[Position + i] != B[i])
                    return false;
            }

            return true;
        }

        public static List<uint> ByteArrayFindAll(byte[] InputBuffer, byte[] ToSearch, ProgressUpdateCallback ProgressCallback)
        {
            List<uint> Found = new List<uint>();

            for (int i = 0; i < InputBuffer.Length - ToSearch.Length; i++)
            {
                if (ProgressCallback != null)
                {
                    ProgressCallback((int)Math.Round(((double)i / (double)InputBuffer.Length) * 100));
                }

                if (BComp(InputBuffer, i, ToSearch))
                {
                    Found.Add((uint)i);
                }
            }

            return Found;
        }
    }
}
