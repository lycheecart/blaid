#define _XOPEN_SOURCE_EXTENDED
#include <test.priv.h>

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#if USE_WIDEC_SUPPORT && USE_LIBFORM && (defined(NCURSES_VERSION_PATCH) && NCURSES_VERSION_PATCH >= 20131207)
#include <form.h>

#define NUMFIELDS 1

void decToBin(int inputDec, wchar_t* binaryStringBuffer, int buffersize );
void displayFields(FIELD* decField, wchar_t* octBuffer, wchar_t* hexBuffer, wchar_t* binaryStr, int binBufferSize, const wchar_t** decToAscii, const wchar_t** decToShiftJis);

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");

    FIELD* fields[NUMFIELDS + 1];
    FORM* blaidform;
    int i;

    int binBufferSize = 100;
    wchar_t* binaryStr = (wchar_t*) malloc(100*sizeof(wchar_t));
    decToBin(0, binaryStr, binBufferSize);
    const wchar_t* decToAscii[128];
    const wchar_t* decToShiftJis[224];

    decToAscii[0] = L"NULL";
    decToAscii[1] = L"Start of Heading";
    decToAscii[2] = L"Start of Text";
    decToAscii[3] = L"End of Text";
    decToAscii[4] = L"End of Transmission";
    decToAscii[5] = L"Enquiry";
    decToAscii[6] = L"Acknowledgement";
    decToAscii[7] = L"Bell";
    decToAscii[8] = L"Backspace";
    decToAscii[9] = L"Horizontal Tab";
    decToAscii[10] = L"Line Feed";
    decToAscii[11] = L"Vertical Tab";
    decToAscii[12] = L"Form Feed";
    decToAscii[13] = L"Carriage Return";
    decToAscii[14] = L"Shift Out";
    decToAscii[15] = L"Shift In";
    decToAscii[16] = L"Data Link Escape";
    decToAscii[17] = L"Data Control 1";
    decToAscii[18] = L"Data Control 2";
    decToAscii[19] = L"Data Control 3";
    decToAscii[20] = L"Data Control 4";
    decToAscii[21] = L"Negative Acknowledgement";
    decToAscii[22] = L"Synchronous Idle";
    decToAscii[23] = L"End of Transmission Block";
    decToAscii[24] = L"Cancel";
    decToAscii[25] = L"End of Medium";
    decToAscii[26] = L"Substitute";
    decToAscii[27] = L"Escape";
    decToAscii[28] = L"File Seperator";
    decToAscii[29] = L"Group Seperator";
    decToAscii[30] = L"Record Seperator";
    decToAscii[31] = L"Unit Seperator";
    decToAscii[32] = L"Space";
    decToAscii[33] = L"!";
    decToAscii[34] = L"\"";
    decToAscii[35] = L"#";
    decToAscii[36] = L"$";
    decToAscii[37] = L"%";
    decToAscii[38] = L"&";
    decToAscii[39] = L"'";
    decToAscii[40] = L"(";
    decToAscii[41] = L")";
    decToAscii[42] = L"*";
    decToAscii[43] = L"+";
    decToAscii[44] = L",";
    decToAscii[45] = L"-";
    decToAscii[46] = L".";
    decToAscii[47] = L"/";
    decToAscii[48] = L"0";
    decToAscii[49] = L"1";
    decToAscii[50] = L"2";
    decToAscii[51] = L"3";
    decToAscii[52] = L"4";
    decToAscii[53] = L"5";
    decToAscii[54] = L"6";
    decToAscii[55] = L"7";
    decToAscii[56] = L"8";
    decToAscii[57] = L"9";
    decToAscii[58] = L":";
    decToAscii[59] = L";";
    decToAscii[60] = L"<";
    decToAscii[61] = L"=";
    decToAscii[62] = L">";
    decToAscii[63] = L"?";
    decToAscii[64] = L"@";
    decToAscii[65] = L"A";
    decToAscii[66] = L"B";
    decToAscii[67] = L"C";
    decToAscii[68] = L"D";
    decToAscii[69] = L"E";
    decToAscii[70] = L"F";
    decToAscii[71] = L"G";
    decToAscii[72] = L"H";
    decToAscii[73] = L"I";
    decToAscii[74] = L"J";
    decToAscii[75] = L"K";
    decToAscii[76] = L"L";
    decToAscii[77] = L"M";
    decToAscii[78] = L"N";
    decToAscii[79] = L"O";
    decToAscii[80] = L"P";
    decToAscii[81] = L"Q";
    decToAscii[82] = L"R";
    decToAscii[83] = L"S";
    decToAscii[84] = L"T";
    decToAscii[85] = L"U";
    decToAscii[86] = L"V";
    decToAscii[87] = L"W";
    decToAscii[88] = L"X";
    decToAscii[89] = L"Y";
    decToAscii[90] = L"Z";
    decToAscii[91] = L"[";
    decToAscii[92] = L"\\";
    decToAscii[93] = L"]";
    decToAscii[94] = L"^";
    decToAscii[95] = L"_";
    decToAscii[96] = L"`";
    decToAscii[97] = L"a";
    decToAscii[98] = L"b";
    decToAscii[99] = L"c";
    decToAscii[100] = L"d";
    decToAscii[101] = L"e";
    decToAscii[102] = L"f";
    decToAscii[103] = L"g";
    decToAscii[104] = L"h";
    decToAscii[105] = L"i";
    decToAscii[106] = L"j";
    decToAscii[107] = L"k";
    decToAscii[108] = L"l";
    decToAscii[109] = L"m";
    decToAscii[110] = L"n";
    decToAscii[111] = L"o";
    decToAscii[112] = L"p";
    decToAscii[113] = L"q";
    decToAscii[114] = L"r";
    decToAscii[115] = L"s";
    decToAscii[116] = L"t";
    decToAscii[117] = L"u";
    decToAscii[118] = L"v";
    decToAscii[119] = L"w";
    decToAscii[120] = L"x";
    decToAscii[121] = L"y";
    decToAscii[122] = L"z";
    decToAscii[123] = L"{";
    decToAscii[124] = L"|";
    decToAscii[125] = L"}";
    decToAscii[126] = L"~";
    decToAscii[127] = L"Delete";

    decToShiftJis[0] = L"NULL";
    decToShiftJis[1] = L"Start of Heading";
    decToShiftJis[2] = L"Start of Text";
    decToShiftJis[3] = L"End of Text";
    decToShiftJis[4] = L"End of Transmission";
    decToShiftJis[5] = L"Enquiry";
    decToShiftJis[6] = L"Acknowledgement";
    decToShiftJis[7] = L"Bell";
    decToShiftJis[8] = L"Backspace";
    decToShiftJis[9] = L"Horizontal Tab";
    decToShiftJis[10] = L"Line Feed";
    decToShiftJis[11] = L"Vertical Tab";
    decToShiftJis[12] = L"Form Feed";
    decToShiftJis[13] = L"Carriage Return";
    decToShiftJis[14] = L"Shift Out";
    decToShiftJis[15] = L"Shift In";
    decToShiftJis[16] = L"Data Link Escape";
    decToShiftJis[17] = L"Data Control 1";
    decToShiftJis[18] = L"Data Control 2";
    decToShiftJis[19] = L"Data Control 3";
    decToShiftJis[20] = L"Data Control 4";
    decToShiftJis[21] = L"Negative Acknowledgement";
    decToShiftJis[22] = L"Synchronous Idle";
    decToShiftJis[23] = L"End of Transmission Block";
    decToShiftJis[24] = L"Cancel";
    decToShiftJis[25] = L"End of Medium";
    decToShiftJis[26] = L"Substitute";
    decToShiftJis[27] = L"Escape";
    decToShiftJis[28] = L"File Seperator";
    decToShiftJis[29] = L"Group Seperator";
    decToShiftJis[30] = L"Record Seperator";
    decToShiftJis[31] = L"Unit Seperator";
    decToShiftJis[32] = L"Space";
    decToShiftJis[33] = L"!";
    decToShiftJis[34] = L"\"";
    decToShiftJis[35] = L"#";
    decToShiftJis[36] = L"$";
    decToShiftJis[37] = L"%";
    decToShiftJis[38] = L"&";
    decToShiftJis[39] = L"'";
    decToShiftJis[40] = L"(";
    decToShiftJis[41] = L")";
    decToShiftJis[42] = L"*";
    decToShiftJis[43] = L"+";
    decToShiftJis[44] = L",";
    decToShiftJis[45] = L"-";
    decToShiftJis[46] = L".";
    decToShiftJis[47] = L"/";
    decToShiftJis[48] = L"0";
    decToShiftJis[49] = L"1";
    decToShiftJis[50] = L"2";
    decToShiftJis[51] = L"3";
    decToShiftJis[52] = L"4";
    decToShiftJis[53] = L"5";
    decToShiftJis[54] = L"6";
    decToShiftJis[55] = L"7";
    decToShiftJis[56] = L"8";
    decToShiftJis[57] = L"9";
    decToShiftJis[58] = L":";
    decToShiftJis[59] = L";";
    decToShiftJis[60] = L"<";
    decToShiftJis[61] = L"=";
    decToShiftJis[62] = L">";
    decToShiftJis[63] = L"?";
    decToShiftJis[64] = L"@";
    decToShiftJis[65] = L"A";
    decToShiftJis[66] = L"B";
    decToShiftJis[67] = L"C";
    decToShiftJis[68] = L"D";
    decToShiftJis[69] = L"E";
    decToShiftJis[70] = L"F";
    decToShiftJis[71] = L"G";
    decToShiftJis[72] = L"H";
    decToShiftJis[73] = L"I";
    decToShiftJis[74] = L"J";
    decToShiftJis[75] = L"K";
    decToShiftJis[76] = L"L";
    decToShiftJis[77] = L"M";
    decToShiftJis[78] = L"N";
    decToShiftJis[79] = L"O";
    decToShiftJis[80] = L"P";
    decToShiftJis[81] = L"Q";
    decToShiftJis[82] = L"R";
    decToShiftJis[83] = L"S";
    decToShiftJis[84] = L"T";
    decToShiftJis[85] = L"U";
    decToShiftJis[86] = L"V";
    decToShiftJis[87] = L"W";
    decToShiftJis[88] = L"X";
    decToShiftJis[89] = L"Y";
    decToShiftJis[90] = L"Z";
    decToShiftJis[91] = L"[";
    decToShiftJis[92] = L"¥";
    decToShiftJis[93] = L"]";
    decToShiftJis[94] = L"^";
    decToShiftJis[95] = L"_";
    decToShiftJis[96] = L"`";
    decToShiftJis[97] = L"a";
    decToShiftJis[98] = L"b";
    decToShiftJis[99] = L"c";
    decToShiftJis[100] = L"d";
    decToShiftJis[101] = L"e";
    decToShiftJis[102] = L"f";
    decToShiftJis[103] = L"g";
    decToShiftJis[104] = L"h";
    decToShiftJis[105] = L"i";
    decToShiftJis[106] = L"j";
    decToShiftJis[107] = L"k";
    decToShiftJis[108] = L"l";
    decToShiftJis[109] = L"m";
    decToShiftJis[110] = L"n";
    decToShiftJis[111] = L"o";
    decToShiftJis[112] = L"p";
    decToShiftJis[113] = L"q";
    decToShiftJis[114] = L"r";
    decToShiftJis[115] = L"s";
    decToShiftJis[116] = L"t";
    decToShiftJis[117] = L"u";
    decToShiftJis[118] = L"v";
    decToShiftJis[119] = L"w";
    decToShiftJis[120] = L"x";
    decToShiftJis[121] = L"y";
    decToShiftJis[122] = L"z";
    decToShiftJis[123] = L"{";
    decToShiftJis[124] = L"|";
    decToShiftJis[125] = L"}";
    decToShiftJis[126] = L"‾";
    decToShiftJis[127] = L"Delete";
    decToShiftJis[128] = L"<undefined>";
    decToShiftJis[129] = L"<undefined>";
    decToShiftJis[130] = L"<undefined>";
    decToShiftJis[131] = L"<undefined>";
    decToShiftJis[132] = L"<undefined>";
    decToShiftJis[133] = L"<undefined>";
    decToShiftJis[134] = L"<undefined>";
    decToShiftJis[135] = L"<undefined>";
    decToShiftJis[136] = L"<undefined>";
    decToShiftJis[137] = L"<undefined>";
    decToShiftJis[138] = L"<undefined>";
    decToShiftJis[139] = L"<undefined>";
    decToShiftJis[140] = L"<undefined>";
    decToShiftJis[141] = L"<undefined>";
    decToShiftJis[142] = L"<undefined>";
    decToShiftJis[143] = L"<undefined>";
    decToShiftJis[144] = L"<undefined>";
    decToShiftJis[145] = L"<undefined>";
    decToShiftJis[146] = L"<undefined>";
    decToShiftJis[147] = L"<undefined>";
    decToShiftJis[148] = L"<undefined>";
    decToShiftJis[149] = L"<undefined>";
    decToShiftJis[150] = L"<undefined>";
    decToShiftJis[151] = L"<undefined>";
    decToShiftJis[152] = L"<undefined>";
    decToShiftJis[153] = L"<undefined>";
    decToShiftJis[154] = L"<undefined>";
    decToShiftJis[155] = L"<undefined>";
    decToShiftJis[156] = L"<undefined>";
    decToShiftJis[157] = L"<undefined>";
    decToShiftJis[158] = L"<undefined>";
    decToShiftJis[159] = L"<undefined>";
    decToShiftJis[160] = L"<undefined>";
    decToShiftJis[161] = L"｡";
    decToShiftJis[162] = L"｢";
    decToShiftJis[163] = L"｣";
    decToShiftJis[164] = L"､";
    decToShiftJis[165] = L"･";
    decToShiftJis[166] = L"ｦ";
    decToShiftJis[167] = L"ｧ";
    decToShiftJis[168] = L"ｨ";
    decToShiftJis[169] = L"ｩ";
    decToShiftJis[170] = L"ｪ";
    decToShiftJis[171] = L"ｫ";
    decToShiftJis[172] = L"ｬ";
    decToShiftJis[173] = L"ｭ";
    decToShiftJis[174] = L"ｮ";
    decToShiftJis[175] = L"ｯ";
    decToShiftJis[176] = L"ｰ";
    decToShiftJis[177] = L"ｱ";
    decToShiftJis[178] = L"ｲ";
    decToShiftJis[179] = L"ｳ";
    decToShiftJis[180] = L"ｴ";
    decToShiftJis[181] = L"ｵ";
    decToShiftJis[182] = L"ｶ";
    decToShiftJis[183] = L"ｷ";
    decToShiftJis[184] = L"ｸ";
    decToShiftJis[185] = L"ｹ";
    decToShiftJis[186] = L"ｺ";
    decToShiftJis[187] = L"ｻ";
    decToShiftJis[188] = L"ｼ";
    decToShiftJis[189] = L"ｽ";
    decToShiftJis[190] = L"ｾ";
    decToShiftJis[191] = L"ｿ";
    decToShiftJis[192] = L"ﾀ";
    decToShiftJis[193] = L"ﾁ";
    decToShiftJis[194] = L"ﾂ";
    decToShiftJis[195] = L"ﾃ";
    decToShiftJis[196] = L"ﾄ";
    decToShiftJis[197] = L"ﾅ";
    decToShiftJis[198] = L"ﾆ";
    decToShiftJis[199] = L"ﾇ";
    decToShiftJis[200] = L"ﾈ";
    decToShiftJis[201] = L"ﾉ";
    decToShiftJis[202] = L"ﾊ";
    decToShiftJis[203] = L"ﾋ";
    decToShiftJis[204] = L"ﾌ";
    decToShiftJis[205] = L"ﾍ";
    decToShiftJis[206] = L"ﾎ";
    decToShiftJis[207] = L"ﾏ";
    decToShiftJis[208] = L"ﾐ";
    decToShiftJis[209] = L"ﾑ";
    decToShiftJis[210] = L"ﾒ";
    decToShiftJis[211] = L"ﾓ";
    decToShiftJis[212] = L"ﾔ";
    decToShiftJis[213] = L"ﾕ";
    decToShiftJis[214] = L"ﾖ";
    decToShiftJis[215] = L"ﾗ";
    decToShiftJis[216] = L"ﾘ";
    decToShiftJis[217] = L"ﾙ";
    decToShiftJis[218] = L"ﾚ";
    decToShiftJis[219] = L"ﾛ";
    decToShiftJis[220] = L"ﾜ";
    decToShiftJis[221] = L"ﾝ";
    decToShiftJis[222] = L"ﾞ";
    decToShiftJis[223] = L"ﾟ";

    int inputDec = 63;
    if (argc>1) {
        inputDec = atoi(argv[1]);
        wprintf(L"dec %d\noct %o\nhex %x\n", inputDec, inputDec, inputDec);

        wprintf(L"  binary ");
        decToBin(inputDec, binaryStr, binBufferSize);
        wprintf(binaryStr);
        wprintf(L"\n");

        wprintf(L"   ascii ");
        if (inputDec >= 0 && inputDec <= 127) {
            wprintf( decToAscii[inputDec]);
        } else {
            wprintf( L"<undefined>" );
        }
        wprintf(L"\n");

        wprintf(L"shiftjis ");
        if (inputDec >= 0 && inputDec <= 223) {
            wprintf( decToShiftJis[inputDec]);
        } else {
            wprintf( L"<undefined>" );
        }
        wprintf(L"\n");

        return 0;
    }

    wchar_t* octBuffer = (wchar_t*) malloc(100*sizeof(wchar_t));
    wchar_t* hexBuffer = (wchar_t*) malloc(100*sizeof(wchar_t));
    int decValue;
    wchar_t* decChars = NULL;
    wchar_t* binChars = NULL;

    initscr();
    nonl();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(1);

    int fieldh = 1;
    int fieldw = 16;
    int fieldleft = 16;
    int labelCol = 2;

    for (i = 0; i < NUMFIELDS; i++) {
        fields[i] = new_field(fieldh, fieldw, 6, fieldleft, 0, 0);
        set_field_back(fields[i], A_UNDERLINE);
        field_opts_off(fields[i], O_AUTOSKIP);
    }
    fields[i] = NULL;

    blaidform = new_form(fields);
    post_form(blaidform);

    mvaddwstr(6,  labelCol, L"decimal");
    mvaddwstr(12, labelCol, L"octal");
    mvaddwstr(18, labelCol, L"hexadecimal");
    mvaddwstr(24, labelCol, L"binary");
    mvaddwstr(30, labelCol, L"ascii");
    mvaddwstr(36, labelCol, L"shift-jis");

    refresh();
    bool done = FALSE;

    while (!done) {
        wint_t ch;
        int ret = get_wch(&ch);
        switch (ret) {
        case KEY_CODE_YES:
            switch (ch) {
            case KEY_DOWN:
                form_driver_w(blaidform, KEY_CODE_YES, REQ_NEXT_FIELD);
                form_driver_w(blaidform, KEY_CODE_YES, REQ_END_LINE);
            break;
            case KEY_BTAB:
            case KEY_UP:
                form_driver_w(blaidform, KEY_CODE_YES, REQ_PREV_FIELD);
                form_driver_w(blaidform, KEY_CODE_YES, REQ_END_LINE);
            break;

            case KEY_BACKSPACE:
                if (current_field(blaidform) == fields[0]) {
                    form_driver_w(blaidform, KEY_CODE_YES, REQ_DEL_PREV);
                    form_driver_w(blaidform, KEY_CODE_YES, REQ_VALIDATION);
                    displayFields(fields[0], octBuffer, hexBuffer, binaryStr, binBufferSize, decToAscii, decToShiftJis);
                }
            break;

            case KEY_DC:
                if (current_field(blaidform) == fields[0]) {
                    form_driver_w(blaidform, KEY_CODE_YES, REQ_DEL_CHAR);
                    form_driver_w(blaidform, KEY_CODE_YES, REQ_VALIDATION);
                    displayFields(fields[0], octBuffer, hexBuffer, binaryStr, binBufferSize, decToAscii, decToShiftJis);
                }
            break;

            default:
            break;
            }
            break;
        case OK:
            switch (ch) {
            case CTRL('D'):
            case QUIT:
            case ESCAPE:
                done = TRUE;
            break;
            case '\t':
                form_driver_w(blaidform, KEY_CODE_YES, REQ_NEXT_FIELD);
                form_driver_w(blaidform, KEY_CODE_YES, REQ_END_LINE);
            break;
            default:
                form_driver_w(blaidform, OK, (wchar_t) ch);
                form_driver_w(blaidform, KEY_CODE_YES, REQ_VALIDATION);
                displayFields(fields[0], octBuffer, hexBuffer, binaryStr, binBufferSize, decToAscii, decToShiftJis);
            break;
            }
            break;
        }

        refresh();
    }

    unpost_form(blaidform);
    free_form(blaidform);
    for (i = 0; i < NUMFIELDS; i++) {
        free_field(fields[i]);
    }
    endwin();

    exit(0);
}

void decToBin(int inputDec, wchar_t* binaryStringBuffer, int buffersize ) {
    memset(binaryStringBuffer, '\0', buffersize*sizeof(wchar_t));

    int p = 1;

    if (inputDec > 999999999) {
        wcscpy(binaryStringBuffer, L"oops");
        return;
    }

    int greaterPower = p;
    while (greaterPower < inputDec) {
        greaterPower = greaterPower << 1;
        p++; 
    }

    int i = 1;
    int sum = 0;
    wcscpy(binaryStringBuffer, L"0x");

    while (i <= p) { // need to go to [p-1]. [p-1] is the 2**0 spot.
        int powOfTwo = pow(2,( p-i));
        bool goesOver = ( powOfTwo + sum > inputDec);
        if (goesOver) {
            wcscat(binaryStringBuffer, L"0");
        } else {
            wcscat(binaryStringBuffer, L"1");
            sum += powOfTwo;
        }

        i++;
    }
}

void displayFields(FIELD* decField, wchar_t* octBuffer, wchar_t* hexBuffer, wchar_t* binaryStr, int binBufferSize, const wchar_t** decToAscii, const wchar_t** decToShiftJis) {
    int fieldCol = 16;
    int labelCol = 2;

    char* decChars = field_buffer(decField, 0);
    int decValue = atoi(decChars);

    //wchar_t* pend;
    //wchar_t* decChars = field_buffer(decField, 0);  
    //int decValue = (int) wcstol(decChars, &pend, 10); 

    memset(octBuffer, L'\0', 100*sizeof(wchar_t));
    memset(hexBuffer, L'\0', 100*sizeof(wchar_t));

    swprintf(octBuffer, 99, L"%o", decValue);
    swprintf(hexBuffer, 99, L"%x", decValue);

    mvaddwstr(12, 16, octBuffer);
	clrtoeol();
    mvaddwstr(18, 16, hexBuffer);
	clrtoeol();

    decToBin(decValue, binaryStr, binBufferSize);
    mvaddwstr(24, 16, binaryStr) ;
	clrtoeol();

    if (decValue >= 0 && decValue <= 127) {
        mvaddwstr(30, fieldCol, decToAscii[decValue]);
    } else {
        mvaddwstr(30, fieldCol, L"<undefined>");
    }
	clrtoeol();

    if (decValue >= 0 && decValue <= 223) {
        mvaddwstr(36, fieldCol, decToShiftJis[decValue]);
    } else {
        mvaddwstr(36, fieldCol, L"<undefined>");
    }
	clrtoeol();
    move(0,0);
}

#else
int main(void) {
    printf("This program requires the wide-ncurses and forms library\n");
    ExitProgram(EXIT_FAILURE);
}
#endif /* USE_WIDEC_SUPPORT */
