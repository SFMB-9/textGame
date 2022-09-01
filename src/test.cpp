#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::cout << " 0 \u0000 \000 \00 \0\n"; //
    std::cout << " 1 \u0001 \001 \01 \1\n"; // ☺
    std::cout << " 2 \u0002 \002 \02 \2\n"; // ☻
    std::cout << " 3 \u0003 \003 \03 \3\n"; // ♥
    std::cout << " 4 \u0004 \004 \04 \4\n"; // ♦
    std::cout << " 5 \u0005 \005 \05 \5\n"; // ♣
    std::cout << " 6 \u0006 \006 \06 \6\n"; // ♠
    std::cout << " 7 \u0007 \007 \07 \7 \a\n"; // \a
    std::cout << " 8 \u0008 \010 \10 \b\n"; // \b
    std::cout << " 9 \u0009 \011 \11 \t\n"; // \t
    std::cout << "10 \u000A \012 \12 \n\n"; // \n
    std::cout << "11 \u000B \013 \13 \v\n"; // ♂
    std::cout << "12 \u000C \014 \14 \f\n"; // ♀
    std::cout << "13 \u000D \015 \15 \r\n"; // \r
    std::cout << "14 \u000E \016 \16\n"; // ♫
    std::cout << "15 \u000F \017 \17\n"; // ☼
    std::cout << "16 \u0010 \020 \20\n"; // ►
    std::cout << "17 \u0011 \021 \21\n"; // ◄
    std::cout << "18 \u0012 \022 \22\n"; // ↕
    std::cout << "19 \u0013 \023 \23\n"; // ‼
    std::cout << "20 \u0014 \024 \24\n"; // ¶
    std::cout << "21 \u0015 \025 \25\n"; // §
    std::cout << "22 \u0016 \026 \26\n"; // ▬
    std::cout << "23 \u0017 \027 \27\n"; // ↨
    std::cout << "24 \u0018 \030 \30\n";
    std::cout << "25 \u0019 \031 \31\n";
    std::cout << "26 \u001A \032 \32\n";
    std::cout << "27 \u001B \033 \33\n";
    std::cout << "28 \u001C \034 \34\n";
    std::cout << "29 \u001D \035 \35\n";
    std::cout << "30 \u001E \036 \36\n";
    std::cout << "31 \u001F \037 \37\n";
    std::cout << "32 \u0020 \040 \40\n";
    std::cout << "33 \u0021 \041 \41\n"; // !
    std::cout << "34 \u0022 \042 \42\n"; // "
    std::cout << "35 \u0023 \043 \43\n"; // #
    std::cout << "36 \u0024 \044 \44\n"; // $
    std::cout << "37 \u0025 \045 \45\n"; // %
    std::cout << "38 \u0026 \046 \46\n"; // &
    std::cout << "39 \u0027 \047 \47\n"; // '
    std::cout << "40 \u0028 \050 \50\n"; // (
    std::cout << "41 \u0029 \051 \51\n"; // )
    std::cout << "42 \u002A \052 \52\n"; // *
    std::cout << "43 \u002B \053 \53\n"; // +
    std::cout << "44 \u002C \054 \54\n"; // ,
    std::cout << "45 \u002D \055 \55\n"; // -
    std::cout << "46 \u002E \056 \56\n"; // .
    std::cout << "47 \u002F \057 \57\n"; // /
    std::cout << "48 \u0030 \060 \60\n"; // 0
    std::cout << "49 \u0031 \061 \61\n"; // 1
    std::cout << "50 \u0032 \062 \62\n"; // 2
    std::cout << "51 \u0033 \063 \63\n"; // 3
    std::cout << "52 \u0034 \064 \64\n"; // 4
    std::cout << "53 \u0035 \065 \65\n"; // 5
    std::cout << "54 \u0036 \066 \66\n"; // 6
    std::cout << "55 \u0037 \067 \67\n"; // 7
    std::cout << "56 \u0038 \070 \70\n"; // 8
    std::cout << "57 \u0039 \071 \71\n"; // 9
    std::cout << "58 \u003A \072 \72\n"; // :
    std::cout << "59 \u003B \073 \73\n"; // ;
    std::cout << "60 \u003C \074 \74\n"; // <
    std::cout << "61 \u003D \075 \75\n"; // =
    std::cout << "62 \u003E \076 \76\n"; // >
    std::cout << "63 \u003F \077 \77\n"; // ?
    std::cout << "64 \u0040 \100\n"; // @
    std::cout << "65 \u0041 \101\n"; // A
    std::cout << "66 \u0042 \102\n"; // B
    std::cout << "67 \u0043 \103\n"; // C
    std::cout << "68 \u0044 \104\n"; // D
    std::cout << "69 \u0045 \105\n"; // E
    std::cout << "70 \u0046 \106\n"; // F
    std::cout << "71 \u0047 \107\n"; // G
    std::cout << "72 \u0048 \110\n"; // H
    std::cout << "73 \u0049 \111\n"; // I
    std::cout << "74 \u004A \112\n"; // J
    std::cout << "75 \u004B \113\n"; // K
    std::cout << "76 \u004C \114\n"; // L
    std::cout << "77 \u004D \115\n"; // M
    std::cout << "78 \u004E \116\n"; // N
    std::cout << "79 \u004F \117\n"; // O
    std::cout << "80 \u0050 \120\n"; // P
    std::cout << "81 \u0051 \121\n"; // Q
    std::cout << "82 \u0052 \122\n"; // R
    std::cout << "83 \u0053 \123\n"; // S
    std::cout << "84 \u0054 \124\n"; // T
    std::cout << "85 \u0055 \125\n"; // U
    std::cout << "86 \u0056 \126\n"; // V
    std::cout << "87 \u0057 \127\n"; // W
    std::cout << "88 \u0058 \130\n"; // X
    std::cout << "89 \u0059 \131\n"; // Y
    std::cout << "90 \u005A \132\n"; // Z
    std::cout << "91 \u005B \133\n"; // [
    std::cout << "92 \u005C \134\n"; // backslash
    std::cout << "93 \u005D \135\n"; // ]
    std::cout << "94 \u005E \136\n"; // ^
    std::cout << "95 \u005F \137\n"; // _
    std::cout << "96 \u0060 \140\n"; // `
    std::cout << "97 \u0061 \141\n"; // a
    std::cout << "98 \u0062 \142\n"; // b
    std::cout << "99 \u0063 \143\n"; // c
    std::cout << "100 \u0064 \144\n"; // d
    std::cout << "101 \u0065 \145\n"; // e
    std::cout << "102 \u0066 \146\n"; // f
    std::cout << "103 \u0067 \147\n"; // g
    std::cout << "104 \u0068 \150\n"; // h
    std::cout << "105 \u0069 \151\n"; // i
    std::cout << "106 \u006A \152\n"; // j
    std::cout << "107 \u006B \153\n"; // k
    std::cout << "108 \u006C \154\n"; // l
    std::cout << "109 \u006D \155\n"; // m
    std::cout << "110 \u006E \156\n"; // n
    std::cout << "111 \u006F \157\n"; // o
    std::cout << "112 \u0070 \160\n"; // p
    std::cout << "113 \u0071 \161\n"; // q
    std::cout << "114 \u0072 \162\n"; // r
    std::cout << "115 \u0073 \163\n"; // s
    std::cout << "116 \u0074 \164\n"; // t
    std::cout << "117 \u0075 \165\n"; // u
    std::cout << "118 \u0076 \166\n"; // v
    std::cout << "119 \u0077 \167\n"; // w
    std::cout << "120 \u0078 \170\n"; // x
    std::cout << "121 \u0079 \171\n"; // y
    std::cout << "122 \u007A \172\n"; // z
    std::cout << "123 \u007B \173\n"; // {
    std::cout << "124 \u007C \174\n"; // |
    std::cout << "125 \u007D \175\n"; // }
    std::cout << "126 \u007E \176\n"; // ~
    std::cout << "127 \u007F \177\n"; // DEL
    std::cout << "128 \200\n"; // Ç
    std::cout << "129 \201\n"; // ü
    std::cout << "130 \202\n"; // é
    std::cout << "131 \203\n"; // â
    std::cout << "132 \204\n"; // ä
    std::cout << "133 \205\n"; // à
    std::cout << "134 \206\n"; // å
    std::cout << "135 \207\n"; // ç
    std::cout << "136 \210\n"; // ê
    std::cout << "137 \211\n"; // ë
    std::cout << "138 \212\n"; // è
    std::cout << "139 \213\n"; // ï
    std::cout << "140 \214\n"; // î
    std::cout << "141 \215\n"; // ì
    std::cout << "142 \216\n"; // Ä
    std::cout << "143 \217\n"; // Å
    std::cout << "144 \220\n"; // É
    std::cout << "145 \221\n"; // æ
    std::cout << "146 \222\n"; // Æ
    std::cout << "147 \223\n"; // ô
    std::cout << "148 \224\n"; // ö
    std::cout << "149 \225\n"; // ò
    std::cout << "150 \226\n"; // û
    std::cout << "151 \227\n"; // ù
    std::cout << "152 \230\n"; // ÿ
    std::cout << "153 \231\n"; // Ö
    std::cout << "154 \232\n"; // Ü
    std::cout << "155 \233\n"; // ø
    std::cout << "156 \234\n"; // £
    std::cout << "157 \235\n"; // Ø
    std::cout << "158 \236\n"; // ×
    std::cout << "159 \237\n"; // ƒ
    std::cout << "160 \240\n"; // á
    std::cout << "161 \241\n"; // í
    std::cout << "162 \242\n"; // ó
    std::cout << "163 \243\n"; // ú
    std::cout << "164 \244\n"; // ñ
    std::cout << "165 \245\n"; // Ñ
    std::cout << "166 \246\n"; // ª
    std::cout << "167 \247\n"; // º
    std::cout << "168 \250\n"; // ¿
    std::cout << "169 \251\n"; // ®
    std::cout << "170 \252\n"; // ¬
    std::cout << "171 \253\n"; // ½
    std::cout << "172 \254\n"; // ¼
    std::cout << "173 \255\n"; // ¡
    std::cout << "174 \256\n"; // «
    std::cout << "175 \257\n"; // »
    std::cout << "176 \260\n"; // ░
    std::cout << "177 \261\n"; // ▒
    std::cout << "178 \262\n"; // ▓
    std::cout << "179 \263\n"; // │
    std::cout << "180 \264\n"; // ┤
    std::cout << "181 \265\n"; // Á
    std::cout << "182 \266\n"; // Â
    std::cout << "183 \267\n"; // À
    std::cout << "184 \270\n"; // ©
    std::cout << "185 \271\n"; // ╣
    std::cout << "186 \272\n"; // ║
    std::cout << "187 \273\n"; // ╗
    std::cout << "188 \274\n"; // ╝
    std::cout << "189 \275\n"; // ¢
    std::cout << "190 \276\n"; // ¥
    std::cout << "191 \277\n"; // ┐
    std::cout << "192 \300\n"; // └
    std::cout << "193 \301\n"; // ┴
    std::cout << "194 \302\n"; // ┬
    std::cout << "195 \303\n"; // ├
    std::cout << "196 \304\n"; // ─
    std::cout << "197 \305\n"; // ┼
    std::cout << "198 \306\n"; // ã
    std::cout << "199 \307\n"; // Ã
    std::cout << "200 \310\n"; // ╚
    std::cout << "201 \311\n"; // ╔
    std::cout << "202 \312\n"; // ╩
    std::cout << "203 \313\n"; // ╦
    std::cout << "204 \314\n"; // ╠
    std::cout << "205 \315\n"; // ═
    std::cout << "206 \316\n"; // ╬
    std::cout << "207 \317\n"; // ¤
    std::cout << "208 \320\n"; // ð
    std::cout << "209 \321\n"; // Ð
    std::cout << "210 \322\n"; // Ê
    std::cout << "211 \323\n"; // Ë
    std::cout << "212 \324\n"; // È
    std::cout << "213 \325\n"; // ı
    std::cout << "214 \326\n"; // Í
    std::cout << "215 \327\n"; // Î
    std::cout << "216 \330\n"; // Ï
    std::cout << "217 \331\n"; // ┘
    std::cout << "218 \332\n"; // ┌
    std::cout << "219 \333\n"; // █
    std::cout << "220 \334\n"; // ▄
    std::cout << "221 \335\n"; // ¦
    std::cout << "222 \336\n"; // Ì
    std::cout << "223 \337\n"; // ▀
    std::cout << "224 \340\n"; // Ó
    std::cout << "225 \341\n"; // ß
    std::cout << "226 \342\n"; // Ô
    std::cout << "227 \343\n"; // Ò
    std::cout << "228 \344\n"; // õ
    std::cout << "229 \345\n"; // Õ
    std::cout << "230 \346\n"; // µ
    std::cout << "231 \347\n"; // þ
    std::cout << "232 \350\n"; // Þ
    std::cout << "233 \351\n"; // Ú
    std::cout << "234 \352\n"; // Û
    std::cout << "235 \353\n"; // Ù
    std::cout << "236 \354\n"; // ý
    std::cout << "237 \355\n"; // Ý
    std::cout << "238 \356\n"; // ¯
    std::cout << "239 \357\n"; // ´
    std::cout << "240 \360\n"; // ­
    std::cout << "241 \361\n"; // ±
    std::cout << "242 \362\n"; // ‗
    std::cout << "243 \363\n"; // ¾
    std::cout << "244 \364\n"; // ¶
    std::cout << "245 \365\n"; // §
    std::cout << "246 \366\n"; // ÷
    std::cout << "247 \367\n"; // ¸
    std::cout << "248 \370\n"; // °
    std::cout << "249 \371\n"; // ¨
    std::cout << "250 \372\n"; // ·
    std::cout << "251 \373\n"; // ¹
    std::cout << "252 \374\n"; // ³
    std::cout << "253 \375\n"; // ²
    std::cout << "254 \376\n"; // ■
    std::cout << "255 \377\n"; //
    //std::cout << "256 \400\n"; // OUT OF RANGE

    return 0;
}