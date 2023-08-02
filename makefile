COURSE = cs240
SEMESTER = spring2022

# Update the CP_NUMBER if you adapt this makefile for future assignments
CP_NUMBER = 3

# Change the following to your own information
LASTNAME = bozan
GITUSERID = nilsubozan

# The name of the executable
EXE = Pars

# Name files according to CS240 naming conventions
REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar


# Store executables in a subdirectory
#all: $(BIN)/$(EXE)

# Reflects how the files may have been named in CP0
#$(BIN)/$(EXE): $(OBJ)/Animal.o $(OBJ)/Pars.o
#	$(CC) $(FLAGS) $(OBJ)/Animal.o $(OBJ)/Pars.o -o $@

#$(OBJ)/Animal.o: Animal.cpp Animal.h 
#	$(CC) $(FLAGS) -c Animal.cpp -o $@

#$(OBJ)/Pars.o: Pars.cpp Pars.h Animal.h 
#	$(CC) $(FLAGS) -c Pars.cpp -o $@

# Update to add targets for your other .o files, following the Play.o sample

# Run make tar to build a .tar.gz file appropriate for uploading to Brightspace
#tar:	clean
#	tar cvvf $(TARFILE) $(REPODIR)
#	gzip $(TARFILE)

#clean:
#	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz

#
madness: Pars.cpp Pars.h
	g++ -Wall -Wextra Pars.cpp Animal.cpp -o bin/Pars

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm bin/Pars
