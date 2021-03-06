#
# Makefile for MD++ simulation package
# by Wei Cai  caiwei@stanford.edu
# Creation Date : Mon Oct 20 15:47:55 2003 
# Last Modified : Fri Sep  5 17:32:07 2008

SYS = gpp
MAKE= make
TCL = yes
TK  = no
TOB = no
PME = no
BOOST = no
HDF5 = no
OCTAVE = no
GSL = no
STRINGMETHOD = no
CUDA = yes
PY = no
MPI = no
RLIB = no
ELASTIC = yes

#Other system options (see Makfile.base) 
#SYS = gcc/gps/ibm/SunOS/IP22/IP27/i686/i586

include ../src/Makefile.base

#OPT+=-I/usr/X11R6/include (defunct)
OPT+=

GEN+= -DNO_VSNPRINTF -DNO_XPM -DDEPTH=32
GEN+= -D__GNU_LIBRARY__ -D_SEM_SEMUN_UNDEFINED
GEN+= -I/usr/include/GL
#GEN+= -DNOPREPROCESS

LIBS=general.o filecls.o organizer.o scparser.o display.o relax_zxcgr.o relax_prplus.o
EXTERN_SRCS=display.h display.cpp filecls.h filecls.cpp general.h general.cpp linalg3.h main.cpp md.h mdparallel.h mdparallel.cpp namecolor.c organizer.h organizer.cpp relax_prplus.h relax_prplus.cpp relax_zxcgr.h relax_zxcgr.cpp scparser.h scparser.cpp

ifeq ($(RLIB),yes)
  TCL=no
  PY=no
  GEN += -D_USE_R -DSTRICT_R_HEADERS -DR_NO_REMAP -DNOPREPROCESS $(RINCLUDE.$(SYS))
  XLIBS += $(RLIBS.$(SYS))
  define link
   $(CC) -c $< $(GEN) 
  endef
  define rshlib
   MAKEFLAGS="CC=$(CC) SHLIB_LD=$(CC)" R CMD SHLIB $(patsubst %.cpp,%.o,$^) $(XLIBS) $(LINK) -o ../$(BIN)/$@_r.so
  endef
else
  define rshlib
  endef
endif

ifeq ($(ELASTIC),yes)
  GEN += -D_ELASTIC
endif

ifeq ($(PY),yes)
  TCL=no
  GEN += -D_USEPY -DNOPREPROCESS $(PYINCLUDE.$(SYS))
  XLIBS += $(PYLIBS.$(SYS))
endif

ifeq ($(TCL),yes)
  GEN += -D_USETCL -ITcl_include
  XLIBS+= $(TCLLIBS.$(SYS))
  ifeq ($(TK),yes)
    GEN += -D_USETK
    XLIBS+= $(TKLIBS.$(SYS))
  endif
endif

ifeq ($(BOOST),yes)
  GEN += -D_USEBOOST -I"$(HOME)/usr/include"
  XLIBS+= $(BOOSTLIBS.$(SYS))
endif

ifeq ($(HDF5),yes)
  GEN += -D_USEHDF5 $(HDF5INCLUDE.$(SYS))
  XLIBS+= $(HDF5LIBS.$(SYS))
endif

ifeq ($(OCTAVE),yes)
  GEN += -D_USEOCTAVE $(OCTAVEINC.$(SYS))
  XLIBS+= $(OCTAVELIBS.$(SYS))
endif

ifeq ($(TOB),yes)
  GEN += -D_TORSION_OR_BENDING
  FORTRAN_SPEC += -D_TORSION_OR_BENDING
endif

ifeq ($(PME),yes)
  GEN += -D_USEFFTW $(FFTWINCLUDE.$(SYS))
  XLIBS+= $(FFTWLIBS.$(SYS))
endif

ifeq ($(GSL),yes)
  GEN += -D_GSL $(GSLINCLUDE.$(SYS))
  XLIBS+= $(GSLLIBS.$(SYS))
endif

ifeq ($(STRINGMETHOD),yes)
  GEN += -D_STRINGMETHOD $(LAPACKINCLUDE.$(SYS))
  XLIBS+= $(LAPACKLIBS)
endif

ifeq ($(CUDA),yes)
  GEN += -D_USECUDA 
  #GEN += -D_USECUDA  -D_USEFLOAT 
  XLIBS+= 
endif


.PHONY: clean backup sys

all: phasefield
#all: md alglue eam fs lj meam sw swge swsige vaspbox xgeo
#	echo "Fortran codes can be compiled manually by"
#	echo "make FMGPT EAM FS FS2 SW CR ALGLUE"

ifeq ($(CUDA),yes)
phasefield: phasefield.cpp phasefield_cuda.o $(LIBS)
	$(link) -D_TEST $(XLIBS)
	$(rshlib)
else
ifeq ($(MPI),yes)
phasefield: phasefield.cpp $(LIBS) libstk.so 
	$(link) -D_TEST $(XLIBS)
	$(rshlib)

libstk.so:
	cd StencilToolkit; make; cd ..
else
phasefield: phasefield.cpp $(LIBS) 
	$(link) -D_TEST $(XLIBS)
	$(rshlib)
endif
endif

phasefield_grain_Fan: phasefield_grain_Fan.cpp $(LIBS)
	$(link) -D_TEST $(XLIBS)
	$(rshlib)

phasefield_grain_Takaki: phasefield_grain_Takaki.cpp $(LIBS)
	$(link) -D_TEST $(XLIBS)
	$(rshlib)

phasefield.cpp: $(EXTERN_SRCS)
phasefield_grain_Fan.cpp: $(EXTERN_SRCS)
phasefield_grain_Takaki.cpp: $(EXTERN_SRCS)

$(EXTERN_SRCS): ../src/$@ 
	- @ ln -s  ../src/$@ .

# Utilities and tests
ddrij: cal_ddrij.cpp md.o mdparallel.o general.o $(LIBS)
	$(link) -D_TEST  $(XLIBS)
	$(rshlib)

disp: display.cpp general.o
	$(link) -D_TEST $(XLIBS)
	$(rshlib)

scparser: scparser.cpp general.o
	$(link) -D_TEST
	$(rshlib)

organizer: organizer.cpp filecls.o scparser.o general.o
	$(link) -D_TEST
	$(rshlib)

cn2pdb:cn2pdb.cpp filecls.o general.o
	$(link) -D_CN2PDB 
	$(rshlib)

xgeo: xgeo.o $(LIBS)
	$(link)  $(XLIBS)
	$(rshlib)

vaspbox: vaspbox.o md.o $(LIBS)
	$(link)  $(XLIBS)
	$(rshlib)

sys:
	SYS=`uname`; export SYS

backup:
	cp -f *.f *.h *.cpp Makefile backup

clean::
	rm -f display.h display.cpp filecls.h filecls.cpp general.h general.cpp linalg3.h main.cpp md.h mdparallel.h mdparallel.cpp namecolor.c organizer.h organizer.cpp relax_prplus.h relax_prplus.cpp relax_zxcgr.h relax_zxcgr.cpp scparser.h scparser.cpp


Makefile::
	makedepend -Y *.cpp

md.o: integrators.cpp mc_fracatom.cpp stringmethod.cpp us.cpp crystal_order.cpp ffs.cpp ewald.cpp lattice.h solidangle.c namecolor.c colormap.h main.cpp

# DO NOT DELETE

alglue.o: alglue.h mdparallel.h md.h general.h organizer.h scparser.h
alglue.o: filecls.h display.h linalg3.h relax_zxcgr.h relax_prplus.h
bmb.o: bmb.h mdparallel.h md.h general.h organizer.h scparser.h filecls.h
bmb.o: display.h linalg3.h relax_zxcgr.h relax_prplus.h
cal_ddrij.o: cal_ddrij.h general.h linalg3.h md.h
cn2pdb.o: general.h linalg3.h filecls.h
display.o: display.h general.h
display_win.o: display_win.h general.h
eam.o: eam.h mdparallel.h md.h general.h organizer.h scparser.h filecls.h
eam.o: display.h linalg3.h relax_zxcgr.h relax_prplus.h
filecls.o: filecls.h general.h
fs.o: fs.h mdparallel.h md.h general.h organizer.h scparser.h filecls.h
fs.o: display.h linalg3.h relax_zxcgr.h relax_prplus.h
general.o: general.h
ising.o: ising.h general.h organizer.h scparser.h filecls.h display.h
lj2.o: lj2.h mdparallel.h md.h general.h organizer.h scparser.h filecls.h
lj2.o: display.h linalg3.h relax_zxcgr.h relax_prplus.h
ljbond.o: ljbond.h mdparallel.h md.h general.h organizer.h scparser.h
ljbond.o: filecls.h display.h linalg3.h relax_zxcgr.h relax_prplus.h
lj.o: lj.h mdparallel.h md.h general.h organizer.h scparser.h filecls.h
lj.o: display.h linalg3.h relax_zxcgr.h relax_prplus.h
ljdimer.o: ljdimer.h mdparallel.h md.h general.h organizer.h scparser.h
ljdimer.o: filecls.h display.h linalg3.h relax_zxcgr.h relax_prplus.h
md.o: integrators.cpp lattice.h namecolor.c colormap.h main.cpp
md.o: md.h general.h organizer.h scparser.h filecls.h display.h linalg3.h
md.o: relax_zxcgr.h relax_prplus.h 
mdparallel.o: mdparallel.h md.h general.h organizer.h scparser.h filecls.h
mdparallel.o: display.h linalg3.h relax_zxcgr.h relax_prplus.h
meam-baskes.o: meam-baskes.h mdparallel.h md.h general.h organizer.h
meam-baskes.o: scparser.h filecls.h display.h linalg3.h relax_zxcgr.h
meam-baskes.o: relax_prplus.h
meam.o: meam.h mdparallel.h md.h general.h organizer.h scparser.h filecls.h
meam.o: display.h linalg3.h relax_zxcgr.h relax_prplus.h
meam-lammps.o: meam-lammps.h mdparallel.h md.h general.h organizer.h
meam-lammps.o: scparser.h filecls.h display.h linalg3.h relax_zxcgr.h
meam-lammps.o: relax_prplus.h
meam-lenosky.o: meam-lenosky.h mdparallel.h md.h general.h organizer.h
meam-lenosky.o: scparser.h filecls.h display.h linalg3.h relax_zxcgr.h
meam-lenosky.o: relax_prplus.h
meam-marian.o: meam-marian.h mdparallel.h md.h general.h organizer.h
meam-marian.o: scparser.h filecls.h display.h linalg3.h relax_zxcgr.h
meam-marian.o: relax_prplus.h
meam.wei.o: meam.h mdparallel.h md.h general.h organizer.h scparser.h
meam.wei.o: filecls.h display.h linalg3.h relax_zxcgr.h relax_prplus.h
organizer.o: organizer.h scparser.h filecls.h general.h
relax_prplus.o: general.h scparser.h
relax_zxcgr.o: general.h scparser.h
rods.o: rods.h mdparallel.h md.h general.h organizer.h scparser.h filecls.h
rods.o: display.h linalg3.h relax_zxcgr.h relax_prplus.h
scparser.o: general.h scparser.h
siedip.o: siedip.h mdparallel.h md.h general.h organizer.h scparser.h
siedip.o: filecls.h display.h linalg3.h relax_zxcgr.h relax_prplus.h
silica-bksmod.o: silica-bksmod.h mdparallel.h md.h general.h organizer.h
silica-bksmod.o: scparser.h filecls.h display.h linalg3.h relax_zxcgr.h
silica-bksmod.o: relax_prplus.h
stringmethod.o: stringmethod.h
sw.o: sw.h mdparallel.h md.h general.h organizer.h scparser.h filecls.h
sw.o: display.h linalg3.h relax_zxcgr.h relax_prplus.h
swlj.o: swlj.h mdparallel.h md.h general.h organizer.h scparser.h filecls.h
swlj.o: display.h linalg3.h relax_zxcgr.h relax_prplus.h
swsiau.o: swsiau.h mdparallel.h md.h general.h organizer.h scparser.h
swsiau.o: filecls.h display.h linalg3.h relax_zxcgr.h relax_prplus.h
swsige.o: swsige.h mdparallel.h md.h general.h organizer.h scparser.h
swsige.o: filecls.h display.h linalg3.h relax_zxcgr.h relax_prplus.h
swgan.o: swgan.h mdparallel.h md.h general.h organizer.h scparser.h
swgan.o: filecls.h display.h linalg3.h relax_zxcgr.h relax_prplus.h
tersoff.o: tersoff.h mdparallel.h md.h general.h organizer.h scparser.h
tersoff.o: filecls.h display.h linalg3.h relax_zxcgr.h relax_prplus.h
tersoff88.o: tersoff88.h mdparallel.h md.h general.h organizer.h scparser.h
tersoff88.o: filecls.h display.h linalg3.h relax_zxcgr.h relax_prplus.h
murty95.o: murty95.h mdparallel.h md.h general.h organizer.h scparser.h
murty95.o: filecls.h display.h linalg3.h relax_zxcgr.h relax_prplus.h
murty2013.o: murty95.h mdparallel.h md.h general.h organizer.h scparser.h
murty2013.o: filecls.h display.h linalg3.h relax_zxcgr.h relax_prplus.h
vaspbox.o: mdparallel.h md.h general.h organizer.h scparser.h filecls.h
vaspbox.o: display.h linalg3.h relax_zxcgr.h relax_prplus.h main.cpp
xgeo.o: xgeo.h mdparallel.h md.h general.h organizer.h scparser.h filecls.h
xgeo.o: display.h linalg3.h relax_zxcgr.h relax_prplus.h namecolor.c main.cpp
