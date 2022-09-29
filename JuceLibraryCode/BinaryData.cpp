/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== hardsid.dll how to and hints.txt ==================
static const unsigned char temp_binary_data_0[] =
"HardSID_SoftFlush can be used to indicate the hardsid.dll to immediately write the data buffer to the hardware \n"
"(it sends the software buffer to the hardware) and then empty the software buffer.\n"
"\n"
"It is only used by ACID64 to mute or stop the SID sound. E.g. $00 is written to $d418 and then HardSID_SoftFlush \n"
"is called to make it effective immediately.\n"
"\n"
"HardSID_Flush is used to empty the hardware buffer. This will not clear the software buffer.\n"
"\n"
"You need to provide cycle information for your writes to the SID to make the writes exact.\n"
"For USB hardware a software buffer is used to optimize the latency of the USB interface.\n"
"\n"
"You can decide to write every 20 millisecond to the hardware for your synthesizer and gather\n"
"all writes for this time frame and have e.g. 8 cycles between the writes and the last write of the time frame\n"
"should tell the remain cycles of this 20 millisecond.\n"
"\n"
"So e.g. you have 3 writes for this frame:\n"
"\n"
"FRAME_IN_CYCLES = 17734475 / 18 / 50;   // 50Hz in cycles for PAL clock\n"
"\n"
"cycles = 0;\n"
"\n"
"HardSID_Try_Write(0, cycles, 0x04, $41);\n"
"\n"
"cycles += 8;\n"
"\n"
"HardSID_Try_Write(0, cycles, 0x0b, $41);\n"
"\n"
"cycles += 8;\n"
"\n"
"HardSID_Try_Write(0, FRAME_IN_CYCLES - cycles, 0x12, $41);\n"
"\n"
"So the above writes write to device 0. First write writes to register\n"
"4, second to 11 and last to 18. The last write makes sure that the\n"
"next frame starts 20 milliseconds later.\n"
"\n"
"Make sure you use the HardSID_Try_Write method and check the return\n"
"value to see if the software or hardware buffer is full. If that\xe2\x80\x99s the\n"
"case you need to wait a few milliseconds and try again.\n"
"\n"
"You need to make sure the buffer is always filled so that the timing is always correct.\n"
"\n"
"If you don't have anything to write for a frame, then just do this:\n"
"\n"
"HardSID_Try_Write(0, FRAME_IN_CYCLES, 0x1e, 0);\n"
"\n"
"This will write 0 to SID register $1E which will do nothing.\n"
"\n"
"--------------------------------------------------------------------------------------------------------------------------------------------\n"
"\n"
"If you simply want write to the sid at any given time just supply 0 as the cycle parameter, then the write will be scheduled immediately.\n"
"\n"
"The cycle exact timing is mainly neede because c64 music players handle the different sid \"bugs\" in very specific ways.\n"
"For example: If you're not careful when you write to the gate and adsr registers, you can get no sound at all.\n"
"Google \"sid adsr\" for more information.\n"
"\n"
"-Stein\n"
"\n"
"--------------------------------------------------------------------------------------------------------------------------------------------\n"
"\n"
"You can use a global variable to store an instance count.\n"
"Check this in your object_new function and if too high, return null\n"
"(and ideally post an error message to the console)\n"
"to indicate that object construction failed. Otherwise,\n"
"increment the count, and decrement it in the object_free function.\n"
"\n"
"int RS = 0;\n"
"if (x->buffer_index == 0) {\n"
"\twhile (RS != HSID_USB_WSTATE_OK) {\n"
"\t\tRS = HardSID_Try_Write(x->My_Device, FRAME_IN_CYCLES, 0x1e, 0); //do nothing\n"
"\t\tif (RS == HSID_USB_WSTATE_BUSY) systhreat_sleep(20);\n"
"\t\t//if (RS != 1) post(\"RS (Idle) ist %ld\", (long)RS);\n"
"\t}\n"
"\t//post(\"Done, Idle\");\n"
"}\n"
"else {\n"
"\t//eSchreib Puffer\n"
"\tint cycles = 0;\n"
"\tdo {\n"
"\t\tcb_pop_front(x, &x->my_cb, &x->we[x->buffer_index]);\n"
"\t\tif (x->buffer_index == 1) {\n"
"\t\t\tint RS = 0;\n"
"\t\t\twhile (RS != HSID_USB_WSTATE_OK) {\n"
"\t\t\t\tRS = HardSID_Try_Write(x->My_Device, (FRAME_IN_CYCLES - cycles), x->we[x->buffer_index].WE_Reg_NR, x->we[x->buffer_index].WE_Value); //last write\n"
"\t\t\t\tif (RS == HSID_USB_WSTATE_BUSY) systhreat_sleep(20);\n"
"\t\t\t\t//if (RS != 1) post(\"RS (Last Wrtite) ist %ld\", (long)RS);\n"
"\t\t\t}\n"
"\t\t\t//post(\"Last Write\");\n"
"\t\t}\n"
"\t\telse {\n"
"\t\t\tint RS = 0;\n"
"\t\t\twhile (RS != HSID_USB_WSTATE_OK) {\n"
"\t\t\t\tRS = HardSID_Try_Write(x->My_Device, cycles, x->we[x->buffer_index].WE_Reg_NR, x->we[x->buffer_index].WE_Value);\n"
"\t\t\t\tif (RS == HSID_USB_WSTATE_BUSY) systhreat_sleep(20);\n"
"\t\t\t\t\t//if (RS != 1) post(\"RS ist %ld\", (long)RS);\n"
"\t\t\t}\n"
"\t\t\t//post(\"Write with %ld cycles\", (long)cycles);\n"
"\t\t\tsysthreat_sleep(20);\n"
"\t\t\tcycles += 8;\n"
"\t\t}\n"
"\t\tx->buffer_index--;\n"
"\t} while (x->buffer_index > 0);\n"
"}\n";

const char* hardsid_dll_how_to_and_hints_txt = (const char*) temp_binary_data_0;

//================== README.md ==================
static const unsigned char temp_binary_data_1[] =
"todo (for v.1.0):\n"
"-----\n"
"- some factory presets\n"
"- some MIDI CC (switches)\n"
"\n"
"history\n"
"-------\n"
"- 2022/02/01 v.0.9.3\n"
"  - Tune function added\n"
"  - LED indicators for voices added\n"
"- 2021/12/16 app name changed to ASIASS-Uno v.0.9\n"
"  - Poly Mode added\n"
"- 2021/11/08 - releasing v.0.9\n"
"  - PianoRol added (displays and playing notes)\n"
"  - PitchBend added\n"
"  - Link Mode added\n"
"  - SID-Reset added\n"
"  - CC added\n"
"  - created a manual\n"
"  - changed GUI\n"
"  - Init added\n"
"  - changing depricaded juce code\n"
"- 2021/10/01 - releasing v.0.4\n"
"  - MIDI-play modes implemented\n"
"  - MIDI channel select added\n"
"- 2020/02/13 - releasing v.0.1b\n"
"- 2020/02/12 - changing depricaded juce code\n"
"- 2018/10/27 - releasing v.0.1a\n"
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
        case 0xc1b26097:  numBytes = 4062; return hardsid_dll_how_to_and_hints_txt;
        case 0x64791dc8:  numBytes = 712; return README_md;
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
