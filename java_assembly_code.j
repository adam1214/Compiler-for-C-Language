.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 1.000000
	f2i
	istore 0
LABEL_BEGIN:
	iload 0
	i2f
	ldc 6.000000
	fsub
	f2i
	iflt LABEL_TRUE
	goto LABEL_FALSE
LABEL_TRUE:
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 0
	i2f
	ldc 1.000000
	fadd
	f2i
	istore 0
	goto LABEL_BEGIN
LABEL_FALSE:
	goto EXIT_0
EXIT_0:
	return
.end method
