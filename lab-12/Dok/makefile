# put here the path to your header files:
source=code1


.PHONY: clean
 

__ : final-report.pdf
	echo "done"

all: final-report.pdf clean
	echo "done"

# concatenate report with doxygen documentation
final-report.pdf : refman.pdf
	mv ./latex/refman.pdf ./final-report.pdf

# doxygen compilation
refman.pdf : $(source)/gates.h $(source)/gates.cpp $(source)/extended_logic.h $(source)/extended_logic.cpp $(source)/main.cpp Doxyfile
	doxygen 
	$(MAKE) -C latex
# cp ./latex/refman.pdf .
	
# generate configuration file for doxygen
Doxyfile : 
	doxygen -g 	
	mv Doxyfile doxy
	cat doxy | sed -e 's/INPUT[ \t]\+=/INPUT = $(source)/g' | sed -e 's/UML_LOOK[ \t]\+=[ \t]\+NO/UML_LOOK = YES/g' | sed -e 's/HAVE_DOT[ \t]\+=[ \t]\+NO/HAVE_DOT = YES/g' | sed -e 's/PROJECT_NAME[ \t]\+=[ \t]\+"My Project"/PROJECT_NAME = "Fundamentals of Computer Programming: Logic Circuit Simulation"/g' | sed -e 's/FULL_PATH_NAMES[ \t]\+=[ \t]\+YES/FULL_PATH_NAMES = NO/g'  | sed -s 's/GENERATE_HTML[ \t]\+=[ \t]\+YES/GENERATE_HTML = NO/g' > Doxyfile 
	rm doxy 
	
# remove temporary files
clean : 	
	for f in `ls doxy Doxyfile *.aux *.log *.out *.gz *.bib *.blg *.bbl *.o *~ refman.pdf report.pdf` ; do  if [ -f $$f ] ; then rm $$f  ; fi;   done;
	if [ -d latex ] ; then rm -r latex ; fi ;
	if [ -d html ]  ; then rm -r html  ; fi ;
