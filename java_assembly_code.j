.class public compiler_hw3
.super java/lang/Object
.method public static foo(I)I
.limit stack 50
.limit locals 50
	ldc 6
	istore 0
.end method
.method public static lol(I)V
.limit stack 50
.limit locals 50
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 0
	istore 0
	ldc 4
	istore 0
	return
.end method
