; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; SROA fails to rewrite allocs but does rewrite some phis and delete
; dead instructions. Ensure that this invalidates analyses required
; for other passes.
; RUN: opt < %s -passes=bdce,sroa,bdce -o %t -debug-pass-manager 2>&1 | FileCheck %s
; CHECK: Running pass: BDCEPass on H
; CHECK: Running analysis: DemandedBitsAnalysis on H
; CHECK: Running pass: SROAPass on H
; CHECK: Invalidating analysis: DemandedBitsAnalysis on H
; CHECK: Running pass: BDCEPass on H
; CHECK: Running analysis: DemandedBitsAnalysis on H

target datalayout = "e-m:e-i64:64-n32:64"
target triple = "powerpc64le-grtev4-linux-gnu"

%class.b = type { i64 }

declare void @D(ptr sret(%class.b), ptr dereferenceable(32)) local_unnamed_addr

; Function Attrs: nounwind
define void @H(ptr noalias nocapture readnone, [2 x i64], ptr %ptr, i32 signext %v, i64 %l, i64 %idx, ptr nonnull dereferenceable(32) %ptr2) {
  %3 = alloca %class.b, align 8
  %.sroa.0 = alloca i64, align 8
  store i64 0, ptr %.sroa.0, align 8
  %4 = extractvalue [2 x i64] %1, 1
  switch i64 %4, label %6 [
  i64 4, label %foo
  i64 5, label %5
  ]

; <label>:5:
  br label %12

; <label>:6:
  %7 = icmp ugt i64 %4, 5
  br i1 %7, label %8, label %12

; <label>:8:
  %9 = load i8, ptr inttoptr (i64 4 to ptr), align 4
  %10 = icmp eq i8 %9, 47
  %11 = select i1 %10, i64 5, i64 4
  br label %12

; <label>:12:
  %13 = phi ptr [ %.sroa.0, %5 ], [ %.sroa.0, %8 ], [ %.sroa.0, %6 ]
  %14 = phi i64 [ 4, %5 ], [ %11, %8 ], [ 4, %6 ]
  %15 = icmp ne i64 %4, 0
  %16 = icmp ugt i64 %4, %14
  %17 = and i1 %15, %16
  br i1 %17, label %18, label %a.exit

; <label>:18:
  %19 = tail call ptr @memchr(ptr %ptr, i32 signext %v, i64 %l)
  %20 = icmp eq ptr %19, null
  %21 = sext i1 %20 to i64
  br label %a.exit

a.exit:
  %22 = phi i64 [ -1, %12 ], [ %21, %18 ]
  %23 = load ptr, ptr %13, align 8
  %24 = sub nsw i64 %22, %14
  %25 = bitcast ptr %3 to ptr
  call void @llvm.lifetime.start.p0(i64 32, ptr nonnull %25)
  %26 = icmp ult i64 %24, 2
  br i1 %26, label %G.exit, label %27

; <label>:27:
  %28 = getelementptr inbounds i8, ptr %23, i64 %idx
  %29 = icmp eq ptr %28, null
  br i1 %29, label %30, label %31

; <label>:30:
  unreachable

; <label>:31:
  call void @D(ptr nonnull sret(%class.b) %3, ptr nonnull dereferenceable(32) %ptr2)
  br label %G.exit

G.exit:
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %25)
  br label %foo

foo:
  ret void
}

; Function Attrs: nounwind readonly
declare ptr @memchr(ptr, i32 signext, i64) local_unnamed_addr

; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.start.p0(i64, ptr nocapture)

; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.end.p0(i64, ptr nocapture)
