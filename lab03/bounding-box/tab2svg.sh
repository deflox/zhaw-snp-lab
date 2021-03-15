#!/bin/bash

#!/bin/bash

# produces a crude HTML embedded SVG drawing from a tabular file (given on stdin) with columns separated by ":"
# usage: tab2svg < inbut.txt > output.html

awk $* -- '
BEGIN {
   FS=":"   # field-separator: which character separats fields in a record (i.e. in a line)
   print "<!DOCTYPE html>"
   print "<html>"
   print "  <head>"
   print "    <title>SVG Data</title>"
   print "  </head>"
   print "  <body>"
}
/^viewbox/ {
   x = $2
   y = $3
   w = $4
   h = $5
}
/^rect/ {
   if (h > 0) { 
      printf "    <b>board = %dmm x %dmm</b>\n</p>\n", $4, $5
   	  printf "    <svg width=\"%dmm\" viewbox=\"%.1f %.1f %.1f %.1f\" xmlns=\"http://www.w3.org/2000/svg\">\n", $4, x, y, w, h
	  h = 0
   }
   printf "      <rect fill=\"%s\" stroke=\"black\" x=\"%.1f\" y=\"%.1f\" width=\"%.1f\" height=\"%.1f\"/>\n", $6, $2, $3, $4, $5
}
/^polygon/ {
   printf "      <polygon fill=\"%s\" stroke=\"black\" points=\"%.1f,%.1f %.1f,%.1f %.1f,%.1f\"/>\n", $8, $2, $3, $4, $5, $6, $7
}
END {
  print "    </svg>"
  print "  </body>"
  print "</html>"
}
'
