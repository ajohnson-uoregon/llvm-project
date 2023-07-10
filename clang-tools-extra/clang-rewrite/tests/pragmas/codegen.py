names = [
# base directives
["OMPAtomicDirective", "ompAtomicDirective"],
["OMPBarrierDirective", "ompBarrierDirective"],
["OMPCancelDirective", "ompCancelDirective"],
["OMPCancellationPointDirective", "ompCancellationPointDirective"],
["OMPCriticalDirective", "ompCriticalDirective"],
["OMPDepobjDirective", "ompDepobjDirective"],
["OMPDispatchDirective", "ompDispatchDirective"],
["OMPErrorDirective", "ompErrorDirective"],
["OMPFlushDirective", "ompFlushDirective"],
["OMPInteropDirective", "ompInteropDirective"],
["OMPMaskedDirective", "ompMaskedDirective"],
["OMPMasterDirective", "ompMasterDirective"],
["OMPMetaDirective", "ompMetaDirective"],
["OMPOrderedDirective", "ompOrderedDirective"],
["OMPParallelDirective", "ompParallelDirective"],
["OMPParallelMaskedDirective", "ompParallelMaskedDirective"],
["OMPParallelMasterDirective", "ompParallelMasterDirective"],
["OMPParallelSectionsDirective", "ompParallelSectionsDirective"],
["OMPScanDirective", "ompScanDirective"],
["OMPSectionDirective", "ompSectionDirective"],
["OMPSectionsDirective", "ompSectionsDirective"],
["OMPSingleDirective", "ompSingleDirective"],
["OMPTargetDataDirective", "ompTargetDataDirective"],
["OMPTargetDirective", "ompTargetDirective"],
["OMPTargetEnterDataDirective", "ompTargetEnterDataDirective"],
["OMPTargetExitDataDirective", "ompTargetExitDataDirective"],
["OMPTargetParallelDirective", "ompTargetParallelDirective"],
["OMPTargetTeamsDirective", "ompTargetTeamsDirective"],
["OMPTargetUpdateDirective", "ompTargetUpdateDirective"],
["OMPTaskDirective", "ompTaskDirective"],
["OMPTaskgroupDirective", "ompTaskgroupDirective"],
["OMPTaskwaitDirective", "ompTaskwaitDirective"],
["OMPTaskyieldDirective", "ompTaskyieldDirective"],
["OMPTeamsDirective", "ompTeamsDirective"],
# loop directives
["OMPDistributeDirective", "ompDistributeDirective"],
["OMPDistributeParallelForDirective", "ompDistributeParallelForDirective"],
["OMPDistributeParallelForSimdDirective", "ompDistributeParallelForSimdDirective"],
["OMPDistributeSimdDirective", "ompDistributeSimdDirective"],
["OMPForDirective", "ompForDirective"],
["OMPForSimdDirective", "ompForSimdDirective"],
["OMPGenericLoopDirective", "ompGenericLoopDirective"],
["OMPMaskedTaskLoopDirective", "ompMaskedTaskLoopDirective"],
["OMPMaskedTaskLoopSimdDirective", "ompMaskedTaskLoopSimdDirective"],
["OMPMasterTaskLoopDirective", "ompMasterTaskLoopDirective"],
["OMPMasterTaskLoopSimdDirective", "ompMasterTaskLoopSimdDirective"],
["OMPParallelForDirective", "ompParallelForDirective"],
["OMPParallelForSimdDirective", "ompParallelForSimdDirective"],
["OMPParallelGenericLoopDirective", "ompParallelGenericLoopDirective"],
["OMPParallelMaskedTaskLoopDirective", "ompParallelMaskedTaskLoopDirective"],
["OMPParallelMaskedTaskLoopSimdDirective", "ompParallelMaskedTaskLoopSimdDirective"],
["OMPParallelMasterTaskLoopDirective", "ompParallelMasterTaskLoopDirective"],
["OMPParallelMasterTaskLoopSimdDirective", "ompParallelMasterTaskLoopSimdDirective"],
["OMPSimdDirective", "ompSimdDirective"],
["OMPTargetParallelForDirective", "ompTargetParallelForDirective"],
["OMPTargetParallelForSimdDirective", "ompTargetParallelForSimdDirective"],
["OMPTargetParallelGenericLoopDirective", "ompTargetParallelGenericLoopDirective"],
["OMPTargetSimdDirective", "ompTargetSimdDirective"],
["OMPTargetTeamsDistributeDirective", "ompTargetTeamsDistributeDirective"],
["OMPTargetTeamsDistributeParallelForDirective", "ompTargetTeamsDistributeParallelForDirective"],
["OMPTargetTeamsDistributeParallelForSimdDirective", "ompTargetTeamsDistributeParallelForSimdDirective"],
["OMPTargetTeamsDistributeSimdDirective", "ompTargetTeamsDistributeSimdDirective"],
["OMPTargetTeamsGenericLoopDirective", "ompTargetTeamsGenericLoopDirective"],
["OMPTaskLoopDirective", "ompTaskLoopDirective"],
["OMPTaskLoopSimdDirective", "ompTaskLoopSimdDirective"],
["OMPTeamsDistributeDirective", "ompTeamsDistributeDirective"],
["OMPTeamsDistributeParallelForDirective", "ompTeamsDistributeParallelForDirective"],
["OMPTeamsDistributeParallelForSimdDirective", "ompTeamsDistributeParallelForSimdDirective"],
["OMPTeamsDistributeSimdDirective", "ompTeamsDistributeSimdDirective"],
["OMPTeamsGenericLoopDirective", "ompTeamsGenericLoopDirective"],
# loop transform directives
["OMPTileDirective", "ompTileDirective"],
["OMPUnrollDirective", "ompUnrollDirective"],
]


# for (caps, nocaps) in names:
#     print(f"""extern const internal::VariadicDynCastAllOfMatcher<Stmt, {caps}>
#         {nocaps};""")
#
# for (caps, nocaps) in names:
#     print(f"""const internal::VariadicDynCastAllOfMatcher<Stmt, {caps}>
#         {nocaps};""")
#
# for (caps, nocaps) in names:
#     print(f"""REGISTER_MATCHER({nocaps});""")
#
# for (caps, nocaps) in names:
#     print(f"{nocaps},")
#
# for (caps, nocaps) in names:
#     print(f"""case MT::{nocaps}:
#         return handle_openmp_node(root, \"{nocaps}\", level);""")

for (caps, nocaps) in names:
    print(f"""bool Visit{caps}({caps}* dir) {{
        add_node(MT::{nocaps}, "{nocaps}()", getNumChildren(dir) + dir->getNumClauses());

        return true;
    }}""")
