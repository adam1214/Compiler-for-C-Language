.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 2.300000
	fstore 0
	ldc 8.700000
	fstore 1
	fload 0
	fload 1
	fsub
	f2i
	ifge LABEL_GE
	goto EXIT_0
LABEL_GE:
	ldc 111
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
EXIT_0:
	ldc 1
	istore 2
	iload 2
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
