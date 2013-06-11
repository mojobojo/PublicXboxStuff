using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MojosLibs.Binary
{
    class BinaryConversions
    {
        public static byte[] HexStringToByteArray(string str)
        {

            if (str.Length % 2 == 1) str = "0" + str;
            List<byte> ret = new List<byte>();
            for (int i = 0; i < str.Length; i += 2)
                ret.Add(Convert.ToByte(str.Substring(i, 2), 16));
            return ret.ToArray();
        }
    }
}
