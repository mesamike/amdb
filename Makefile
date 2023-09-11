fresh: clean all

all: amdb.dat

###################################
# Compile the programs we need
fac: fac.c parse.c amdb.h
	gcc -o fac fac.c parse.c

ant: ant.c parse.c amdb.h
	gcc -o ant ant.c parse.c

app: app.c parse.c amdb.h
	gcc -o app app.c parse.c

auths: auths.c parse.c amdb.h
	gcc -o auths auths.c parse.c

amdb: amdb.c parse.c amdb.h
	gcc -o amdb amdb.c parse.c

############################################
# Make data file indexes for quicker seeking


##########################
# Distill the FCC data 
fac.dat: fac facility.dat
	./fac > fac.dat

ant.dat: ant gis_am_ant_sys.dat
	./ant > ant.dat

app.dat: app gis_application.dat
	./app > app.dat

auths.dat: auths fac.dat app.dat ant.dat
	./auths > auths.dat

amdb.dat: amdb auths.dat call_sign_history.dat
	./amdb > amdb.dat

##########################
# Extract the ZIP files
facility.dat: facility.zip
	unzip facility.zip
gis_am_ant_sys.dat: gis_am_ant_sys.zip
	unzip gis_am_ant_sys.zip
gis_application.dat: gis_application.zip
	unzip gis_application.zip

call_sign_history.dat: call_sign_history.zip
	unzip call_sign_history.zip

#############################
# get the ZIP files from FCC 
facility.zip:
	wget https://enterpriseefiling.fcc.gov/dataentry/api/download/dbfile/09-07-2023/facility.zip

gis_am_ant_sys.zip:
	wget https://enterpriseefiling.fcc.gov/dataentry/api/download/dbfile/09-07-2023/gis_am_ant_sys.zip

gis_application.zip:
	wget https://enterpriseefiling.fcc.gov/dataentry/api/download/dbfile/09-07-2023/gis_application.zip

call_sign_history.zip:
	wget ftp://ftp.fcc.gov/pub/Bureaus/MB/Databases/cdbs/call_sign_history.zip


#######################
# cleanup rules
clean:
	rm -f *.dat *.dbf *.idx *.dbt *.txt *.zip *.log

pristine: clean
	rm -f fac ant app auths amdb

