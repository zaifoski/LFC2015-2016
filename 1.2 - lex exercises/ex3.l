%start HREF AA

%%
\<a         BEGIN AA;
<AA>href=\"     BEGIN HREF;
<HREF>[^\"]*      ECHO;
<HREF>\"         BEGIN AA;
<AA>a\>           BEGIN 0;
.
