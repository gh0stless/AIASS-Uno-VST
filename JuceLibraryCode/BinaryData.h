/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   redledoff_png;
    const int            redledoff_pngSize = 2598;

    extern const char*   redledon_png;
    const int            redledon_pngSize = 2874;

    extern const char*   CrazyMidi_grau_png;
    const int            CrazyMidi_grau_pngSize = 32809;

    extern const char*   CrazyMidi_grau_64x64_png;
    const int            CrazyMidi_grau_64x64_pngSize = 5324;

    extern const char*   CrazyMidi_grau_128x128_png;
    const int            CrazyMidi_grau_128x128_pngSize = 21339;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 5;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
