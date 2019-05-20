#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1275822200/C_CLIENT.o \
	${OBJECTDIR}/_ext/1275822200/C_INFO.o \
	${OBJECTDIR}/_ext/1275822200/C_MUTEX.o \
	${OBJECTDIR}/_ext/1275822200/C_SERVEUR.o \
	${OBJECTDIR}/_ext/1275822200/C_THREAD.o \
	${OBJECTDIR}/PRJ_IHM.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/prj_ihm.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/prj_ihm.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/prj_ihm ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1275822200/C_CLIENT.o: ../PRJ_IHM/C_CLIENT.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1275822200
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1275822200/C_CLIENT.o ../PRJ_IHM/C_CLIENT.cpp

${OBJECTDIR}/_ext/1275822200/C_INFO.o: ../PRJ_IHM/C_INFO.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1275822200
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1275822200/C_INFO.o ../PRJ_IHM/C_INFO.cpp

${OBJECTDIR}/_ext/1275822200/C_MUTEX.o: ../PRJ_IHM/C_MUTEX.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1275822200
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1275822200/C_MUTEX.o ../PRJ_IHM/C_MUTEX.cpp

${OBJECTDIR}/_ext/1275822200/C_SERVEUR.o: ../PRJ_IHM/C_SERVEUR.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1275822200
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1275822200/C_SERVEUR.o ../PRJ_IHM/C_SERVEUR.cpp

${OBJECTDIR}/_ext/1275822200/C_THREAD.o: ../PRJ_IHM/C_THREAD.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1275822200
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1275822200/C_THREAD.o ../PRJ_IHM/C_THREAD.cpp

${OBJECTDIR}/PRJ_IHM.o: PRJ_IHM.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/PRJ_IHM.o PRJ_IHM.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/prj_ihm.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
