#!/bin/sh

tmpfiles=""
trap 'rm -fr $tmpfiles' 1 2 3 15

tmpfiles="$tmpfiles uc_width.out"
./test-uc_width2${EXEEXT} > uc_width.out

tmpfiles="$tmpfiles uc_width.ok"
cat > uc_width.ok <<\EOF
0000		0
0020..007E	1
00A0		1
00A1..00AC	A
00AD		0
00AE..02FF	A
0300..036F	0
0370..0482	A
0483..0489	0
048A..0590	A
0591..05BD	0
05BE		A
05BF		0
05C0		A
05C1..05C2	0
05C3		A
05C4..05C5	0
05C6		A
05C7		0
05C8..05FF	A
0600..0603	0
0604..060F	A
0610..061A	0
061B..064A	A
064B..065E	0
065F..066F	A
0670		0
0671..06D5	A
06D6..06E4	0
06E5..06E6	A
06E7..06E8	0
06E9		A
06EA..06ED	0
06EE..070E	A
070F		0
0710		A
0711		0
0712..072F	A
0730..074A	0
074B..07A5	A
07A6..07B0	0
07B1..07EA	A
07EB..07F3	0
07F4..0900	A
0901..0902	0
0903..093B	A
093C		0
093D..0940	A
0941..0948	0
0949..094C	A
094D		0
094E..0950	A
0951..0954	0
0955..0961	A
0962..0963	0
0964..0980	A
0981		0
0982..09BB	A
09BC		0
09BD..09C0	A
09C1..09C4	0
09C5..09CC	A
09CD		0
09CE..09E1	A
09E2..09E3	0
09E4..0A00	A
0A01..0A02	0
0A03..0A3B	A
0A3C		0
0A3D..0A40	A
0A41..0A42	0
0A43..0A46	A
0A47..0A48	0
0A49..0A4A	A
0A4B..0A4D	0
0A4E..0A50	A
0A51		0
0A52..0A6F	A
0A70..0A71	0
0A72..0A74	A
0A75		0
0A76..0A80	A
0A81..0A82	0
0A83..0ABB	A
0ABC		0
0ABD..0AC0	A
0AC1..0AC5	0
0AC6		A
0AC7..0AC8	0
0AC9..0ACC	A
0ACD		0
0ACE..0AE1	A
0AE2..0AE3	0
0AE4..0B00	A
0B01		0
0B02..0B3B	A
0B3C		0
0B3D..0B3E	A
0B3F		0
0B40		A
0B41..0B44	0
0B45..0B4C	A
0B4D		0
0B4E..0B55	A
0B56		0
0B57..0B61	A
0B62..0B63	0
0B64..0B81	A
0B82		0
0B83..0BBF	A
0BC0		0
0BC1..0BCC	A
0BCD		0
0BCE..0C3D	A
0C3E..0C40	0
0C41..0C45	A
0C46..0C48	0
0C49		A
0C4A..0C4D	0
0C4E..0C54	A
0C55..0C56	0
0C57..0C61	A
0C62..0C63	0
0C64..0CBB	A
0CBC		0
0CBD..0CCB	A
0CCC..0CCD	0
0CCE..0CE1	A
0CE2..0CE3	0
0CE4..0D40	A
0D41..0D44	0
0D45..0D4C	A
0D4D		0
0D4E..0D61	A
0D62..0D63	0
0D64..0DC9	A
0DCA		0
0DCB..0DD1	A
0DD2..0DD4	0
0DD5		A
0DD6		0
0DD7..0E30	A
0E31		0
0E32..0E33	A
0E34..0E3A	0
0E3B..0E46	A
0E47..0E4E	0
0E4F..0EB0	A
0EB1		0
0EB2..0EB3	A
0EB4..0EB9	0
0EBA		A
0EBB..0EBC	0
0EBD..0EC7	A
0EC8..0ECD	0
0ECE..0F17	A
0F18..0F19	0
0F1A..0F34	A
0F35		0
0F36		A
0F37		0
0F38		A
0F39		0
0F3A..0F70	A
0F71..0F7E	0
0F7F		A
0F80..0F84	0
0F85		A
0F86..0F87	0
0F88..0F8F	A
0F90..0F97	0
0F98		A
0F99..0FBC	0
0FBD..0FC5	A
0FC6		0
0FC7..102C	A
102D..1030	0
1031		A
1032..1037	0
1038		A
1039..103A	0
103B..103C	A
103D..103E	0
103F..1057	A
1058..1059	0
105A..105D	A
105E..1060	0
1061..1070	A
1071..1074	0
1075..1081	A
1082		0
1083..1084	A
1085..1086	0
1087..108C	A
108D		0
108E..10FF	A
1100..115F	2
1160..135E	A
135F		0
1360..1711	A
1712..1714	0
1715..1731	A
1732..1734	0
1735..1751	A
1752..1753	0
1754..1771	A
1772..1773	0
1774..17B3	A
17B4..17B5	0
17B6		A
17B7..17BD	0
17BE..17C5	A
17C6		0
17C7..17C8	A
17C9..17D3	0
17D4..17DC	A
17DD		0
17DE..180A	A
180B..180D	0
180E..18A8	A
18A9		0
18AA..191F	A
1920..1922	0
1923..1926	A
1927..1928	0
1929..1931	A
1932		0
1933..1938	A
1939..193B	0
193C..1A16	A
1A17..1A18	0
1A19..1AFF	A
1B00..1B03	0
1B04..1B33	A
1B34		0
1B35		A
1B36..1B3A	0
1B3B		A
1B3C		0
1B3D..1B41	A
1B42		0
1B43..1B6A	A
1B6B..1B73	0
1B74..1B7F	A
1B80..1B81	0
1B82..1BA1	A
1BA2..1BA5	0
1BA6..1BA7	A
1BA8..1BA9	0
1BAA..1C2B	A
1C2C..1C33	0
1C34..1C35	A
1C36..1C37	0
1C38..1DBF	A
1DC0..1DE6	0
1DE7..1DFD	A
1DFE..1DFF	0
1E00..200A	A
200B..200F	0
2010..2029	A
202A..202E	0
202F..205F	A
2060..2064	0
2065..2069	A
206A..206F	0
2070..20A8	A
20A9		1
20AA..20CF	A
20D0..20F0	0
20F1..2328	A
2329..232A	2
232B..2DDF	A
2DE0..2DFF	0
2E00..2E7F	A
2E80..3029	2
302A..302F	0
3030..303E	2
303F		A
3040..3098	2
3099..309A	0
309B..4DBF	2
4DC0..4DFF	A
4E00..A4CF	2
A4D0..A66E	A
A66F..A672	0
A673..A67B	A
A67C..A67D	0
A67E..A801	A
A802		0
A803..A805	A
A806		0
A807..A80A	A
A80B		0
A80C..A824	A
A825..A826	0
A827..A8C3	A
A8C4		0
A8C5..A925	A
A926..A92D	0
A92E..A946	A
A947..A951	0
A952..AA28	A
AA29..AA2E	0
AA2F..AA30	A
AA31..AA32	0
AA33..AA34	A
AA35..AA36	0
AA37..AA42	A
AA43		0
AA44..AA4B	A
AA4C		0
AA4D..ABFF	A
AC00..D7A3	2
D7A4..F8FF	A
F900..FAFF	2
FB00..FB1D	A
FB1E		0
FB1F..FDFF	A
FE00..FE0F	0
FE10..FE1F	2
FE20..FE26	0
FE27..FE2F	A
FE30..FE6F	2
FE70..FEFE	A
FEFF		0
FF00..FF60	2
FF61..FFDF	1
FFE0..FFE6	2
FFE7..FFF8	1
FFF9..FFFB	0
FFFC..101FC	1
101FD		0
101FE..10A00	1
10A01..10A03	0
10A04		1
10A05..10A06	0
10A07..10A0B	1
10A0C..10A0F	0
10A10..10A37	1
10A38..10A3A	0
10A3B..10A3E	1
10A3F		0
10A40..1D166	1
1D167..1D169	0
1D16A..1D17A	1
1D17B..1D182	0
1D183..1D184	1
1D185..1D18B	0
1D18C..1D1A9	1
1D1AA..1D1AD	0
1D1AE..1D241	1
1D242..1D244	0
1D245..1FFFF	1
20000..2A6D6	2
2A6D7..2F7FF	1
2F800..2FA1D	2
2FA1E..E0000	1
E0001		0
E0002..E001F	1
E0020..E007F	0
E0080..E00FF	1
E0100..E01EF	0
E01F0..10FFFF	1
EOF

: ${DIFF=diff}
${DIFF} uc_width.ok uc_width.out
result=$?

rm -fr $tmpfiles

exit $result