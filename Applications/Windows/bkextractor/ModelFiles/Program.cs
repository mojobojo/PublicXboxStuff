using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ModelFiles
{
    class Program
    {
        static void Main(string[] args)
        {
            NabModel model = new NabModel();
            //model.Open("C:\\users\\mojobojo\\desktop\\aid_model_banjox_objects_bronzenote - Copy");
            model.Open("C:\\users\\mojobojo\\desktop\\aid_model_banjox_actor_klungo");
            model.TestStuff();
            model.DumpDataSections("C:\\testrobot");
            //model.DumpDataSections("C:\\test");
            //model.Open("C:\\BkExtractedMassive\\AA166A8.bin_data_0\\aid_model_banjox_vehicleparts_body_light_tpanel"); 
            // model.DumpDataSections("C:\\test2");
        }
    }
}
