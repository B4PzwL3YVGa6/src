# $OpenBSD: Makefile,v 1.17 2018/04/07 08:19:19 landry Exp $

.include <bsd.own.mk>

LLVM_V=			6.0.0
CLANG_INTR_INCDIR=	/usr/lib/clang/${LLVM_V}/include

TBLGEN= ${.OBJDIR}/../../../clang-tblgen/clang-tblgen
CLANG_INC=${.CURDIR}/../../../../../llvm/tools/clang/include

.PATH:	${.CURDIR}/../../../../../llvm/tools/clang/lib/Headers

GEN=
HEADERS=	stdalign.h \
		stdatomic.h \
		stdnoreturn.h \
		tgmath.h \
		unwind.h \
		varargs.h \
		module.modulemap \

.if ${MACHINE_ARCH} == "aarch64" || ${MACHINE_ARCH} == "arm"
GEN+=		arm_neon.h
HEADERS+=	arm_acle.h ${GEN}
.elif ${MACHINE_ARCH} == "amd64" || ${MACHINE_ARCH} == "i386"
HEADERS+=	adxintrin.h \
		ammintrin.h \
		avx2intrin.h \
		avx512bitalgintrin.h \
		avx512bwintrin.h \
		avx512cdintrin.h \
		avx512dqintrin.h \
		avx512erintrin.h \
		avx512fintrin.h \
		avx512ifmaintrin.h \
		avx512ifmavlintrin.h \
		avx512pfintrin.h \
		avx512vbmi2intrin.h \
		avx512vbmiintrin.h \
		avx512vbmivlintrin.h \
		avx512vlbitalgintrin.h \
		avx512vlbwintrin.h \
		avx512vlcdintrin.h \
		avx512vldqintrin.h \
		avx512vlintrin.h \
		avx512vlvbmi2intrin.h \
		avx512vlvnniintrin.h \
		avx512vnniintrin.h \
		avx512vpopcntdqintrin.h \
		avx512vpopcntdqvlintrin.h \
		avxintrin.h \
		bmi2intrin.h \
		bmiintrin.h \
		cetintrin.h \
		cpuid.h \
		clflushoptintrin.h \
		clwbintrin.h \
		clzerointrin.h \
		emmintrin.h \
		f16cintrin.h \
		fma4intrin.h \
		fmaintrin.h \
		fxsrintrin.h \
		gfniintrin.h \
		ia32intrin.h \
		immintrin.h \
		lwpintrin.h \
		lzcntintrin.h \
		mm3dnow.h \
		mmintrin.h \
		mm_malloc.h \
		mwaitxintrin.h \
		nmmintrin.h \
		pkuintrin.h \
		pmmintrin.h \
		popcntintrin.h \
		prfchwintrin.h \
		rdseedintrin.h \
		rtmintrin.h \
		shaintrin.h \
		smmintrin.h \
		tbmintrin.h \
		tmmintrin.h \
		vaesintrin.h \
		vpclmulqdqintrin.h \
		wmmintrin.h \
		__wmmintrin_aes.h \
		__wmmintrin_pclmul.h \
		x86intrin.h \
		xmmintrin.h \
		xopintrin.h \
		xsaveintrin.h \
		xsaveoptintrin.h \
		xsavecintrin.h \
		xsavesintrin.h \
		xtestintrin.h
.elif ${MACHINE_ARCH} == "powerpc"
HEADERS+=	altivec.h \
		htmintrin.h \
		htmxlintrin.h
.endif

all:	${HEADERS}

clean cleandir:
	rm -f ${GEN}

install includes: ${HEADERS}
.for dir in /usr/lib/clang /usr/lib/clang/${LLVM_V} ${CLANG_INTR_INCDIR}
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${DIRMODE} \
	    ${DESTDIR}${dir}
.endfor
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m 444 \
	    ${.ALLSRC} ${DESTDIR}${CLANG_INTR_INCDIR}

arm_neon.h: ${CLANG_INC}/clang/Basic/arm_neon.td
	${TBLGEN} -gen-arm-neon -o ${.TARGET} ${.ALLSRC}

.include <bsd.obj.mk>
