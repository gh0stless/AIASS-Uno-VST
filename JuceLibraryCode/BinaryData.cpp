/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== hardsid.dll how to and hints.txt ==================
static const unsigned char temp_binary_data_0[] =
"HardSID_SoftFlush can be used to indicate the hardsid.dll to immediately write the data buffer to the hardware \r\n"
"(it sends the software buffer to the hardware) and then empty the software buffer.\r\n"
"\r\n"
"It is only used by ACID64 to mute or stop the SID sound. E.g. $00 is written to $d418 and then HardSID_SoftFlush \r\n"
"is called to make it effective immediately.\r\n"
"\r\n"
"HardSID_Flush is used to empty the hardware buffer. This will not clear the software buffer.\r\n"
"\r\n"
"You need to provide cycle information for your writes to the SID to make the writes exact.\r\n"
"For USB hardware a software buffer is used to optimize the latency of the USB interface.\r\n"
"\r\n"
"You can decide to write every 20 millisecond to the hardware for your synthesizer and gather\r\n"
"all writes for this time frame and have e.g. 8 cycles between the writes and the last write of the time frame\r\n"
"should tell the remain cycles of this 20 millisecond.\r\n"
"\r\n"
"So e.g. you have 3 writes for this frame:\r\n"
"\r\n"
"FRAME_IN_CYCLES = 17734475 / 18 / 50;   // 50Hz in cycles for PAL clock\r\n"
"\r\n"
"cycles = 0;\r\n"
"\r\n"
"HardSID_Try_Write(0, cycles, 0x04, $41);\r\n"
"\r\n"
"cycles += 8;\r\n"
"\r\n"
"HardSID_Try_Write(0, cycles, 0x0b, $41);\r\n"
"\r\n"
"cycles += 8;\r\n"
"\r\n"
"HardSID_Try_Write(0, FRAME_IN_CYCLES - cycles, 0x12, $41);\r\n"
"\r\n"
"So the above writes write to device 0. First write writes to register\r\n"
"4, second to 11 and last to 18. The last write makes sure that the\r\n"
"next frame starts 20 milliseconds later.\r\n"
"\r\n"
"Make sure you use the HardSID_Try_Write method and check the return\r\n"
"value to see if the software or hardware buffer is full. If that\xe2\x80\x99s the\r\n"
"case you need to wait a few milliseconds and try again.\r\n"
"\r\n"
"You need to make sure the buffer is always filled so that the timing is always correct.\r\n"
"\r\n"
"If you don't have anything to write for a frame, then just do this:\r\n"
"\r\n"
"HardSID_Try_Write(0, FRAME_IN_CYCLES, 0x1e, 0);\r\n"
"\r\n"
"This will write 0 to SID register $1E which will do nothing.\r\n"
"\r\n"
"--------------------------------------------------------------------------------------------------------------------------------------------\r\n"
"\r\n"
"If you simply want write to the sid at any given time just supply 0 as the cycle parameter, then the write will be scheduled immediately.\r\n"
"\r\n"
"The cycle exact timing is mainly neede because c64 music players handle the different sid \"bugs\" in very specific ways.\r\n"
"For example: If you're not careful when you write to the gate and adsr registers, you can get no sound at all.\r\n"
"Google \"sid adsr\" for more information.\r\n"
"\r\n"
"-Stein\r\n"
"\r\n"
"--------------------------------------------------------------------------------------------------------------------------------------------\r\n"
"\r\n"
"You can use a global variable to store an instance count.\r\n"
"Check this in your object_new function and if too high, return null\r\n"
"(and ideally post an error message to the console)\r\n"
"to indicate that object construction failed. Otherwise,\r\n"
"increment the count, and decrement it in the object_free function.\r\n"
"\r\n"
"int RS = 0;\r\n"
"if (x->buffer_index == 0) {\r\n"
"\twhile (RS != HSID_USB_WSTATE_OK) {\r\n"
"\t\tRS = HardSID_Try_Write(x->My_Device, FRAME_IN_CYCLES, 0x1e, 0); //do nothing\r\n"
"\t\tif (RS == HSID_USB_WSTATE_BUSY) systhreat_sleep(20);\r\n"
"\t\t//if (RS != 1) post(\"RS (Idle) ist %ld\", (long)RS);\r\n"
"\t}\r\n"
"\t//post(\"Done, Idle\");\r\n"
"}\r\n"
"else {\r\n"
"\t//eSchreib Puffer\r\n"
"\tint cycles = 0;\r\n"
"\tdo {\r\n"
"\t\tcb_pop_front(x, &x->my_cb, &x->we[x->buffer_index]);\r\n"
"\t\tif (x->buffer_index == 1) {\r\n"
"\t\t\tint RS = 0;\r\n"
"\t\t\twhile (RS != HSID_USB_WSTATE_OK) {\r\n"
"\t\t\t\tRS = HardSID_Try_Write(x->My_Device, (FRAME_IN_CYCLES - cycles), x->we[x->buffer_index].WE_Reg_NR, x->we[x->buffer_index].WE_Value); //last write\r\n"
"\t\t\t\tif (RS == HSID_USB_WSTATE_BUSY) systhreat_sleep(20);\r\n"
"\t\t\t\t//if (RS != 1) post(\"RS (Last Wrtite) ist %ld\", (long)RS);\r\n"
"\t\t\t}\r\n"
"\t\t\t//post(\"Last Write\");\r\n"
"\t\t}\r\n"
"\t\telse {\r\n"
"\t\t\tint RS = 0;\r\n"
"\t\t\twhile (RS != HSID_USB_WSTATE_OK) {\r\n"
"\t\t\t\tRS = HardSID_Try_Write(x->My_Device, cycles, x->we[x->buffer_index].WE_Reg_NR, x->we[x->buffer_index].WE_Value);\r\n"
"\t\t\t\tif (RS == HSID_USB_WSTATE_BUSY) systhreat_sleep(20);\r\n"
"\t\t\t\t\t//if (RS != 1) post(\"RS ist %ld\", (long)RS);\r\n"
"\t\t\t}\r\n"
"\t\t\t//post(\"Write with %ld cycles\", (long)cycles);\r\n"
"\t\t\tsysthreat_sleep(20);\r\n"
"\t\t\tcycles += 8;\r\n"
"\t\t}\r\n"
"\t\tx->buffer_index--;\r\n"
"\t} while (x->buffer_index > 0);\r\n"
"}\r\n";

const char* hardsid_dll_how_to_and_hints_txt = (const char*) temp_binary_data_0;

//================== README.md ==================
static const unsigned char temp_binary_data_1[] =
"todo (for v.1.0):\r\n"
"-----\r\n"
"- some factory presets\r\n"
"- some MIDI CC (switches)\r\n"
"\r\n"
"history\r\n"
"-------\r\n"
"- 2022/02/01 v.0.9.3\r\n"
"  - Tune function added\r\n"
"- 2021/12/16 app name changed to ASIASS-Uno v.0.9\r\n"
"  - Poly Mode added\r\n"
"- 2021/11/08 - releasing v.0.9\r\n"
"  - PianoRol added (displays and playing notes)\r\n"
"  - PitchBend added\r\n"
"  - Link Mode added\r\n"
"  - SID-Reset added\r\n"
"  - CC added\r\n"
"  - created a manual\r\n"
"  - changed GUI\r\n"
"  - Init added\r\n"
"  - changing depricaded juce code\r\n"
"- 2021/10/01 - releasing v.0.4\r\n"
"  - MIDI-play modes implemented\r\n"
"  - MIDI channel select added\r\n"
"- 2020/02/13 - releasing v.0.1b\r\n"
"- 2020/02/12 - changing depricaded juce code\r\n"
"- 2018/10/27 - releasing v.0.1a\r\n"
"- 2017/10/28 - starting to code";

const char* README_md = (const char*) temp_binary_data_1;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes);
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xc1b26097:  numBytes = 4164; return hardsid_dll_how_to_and_hints_txt;
        case 0x64791dc8:  numBytes = 703; return README_md;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "hardsid_dll_how_to_and_hints_txt",
    "README_md"
};

const char* originalFilenames[] =
{
    "hardsid.dll how to and hints.txt",
    "README.md"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
