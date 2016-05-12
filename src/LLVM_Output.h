#ifndef HALIDE_LLVM_OUTPUTS_H
#define HALIDE_LLVM_OUTPUTS_H

/** \file
 *
 */

#include <memory>
#include "Module.h"

namespace llvm {
class Module;
class TargetOptions;
class LLVMContext;
}

namespace Halide {

/** Generate an LLVM module. */
EXPORT std::unique_ptr<llvm::Module> compile_module_to_llvm_module(const Module &module, llvm::LLVMContext &context);

/** Compile an LLVM module to native targets (objects, native assembly). */
// @{
EXPORT void compile_llvm_module_to_object(llvm::Module &module, const std::string &filename);
EXPORT void compile_llvm_module_to_assembly(llvm::Module &module, const std::string &filename);
EXPORT void compile_llvm_module_to_native(llvm::Module &module,
                                          const std::string &object_filename,
                                          const std::string &assembly_filename);
// @}

/** Compile an LLVM module to LLVM targets (bitcode, LLVM assembly). */
// @{
EXPORT void compile_llvm_module_to_llvm_bitcode(llvm::Module &module, const std::string &filename);
EXPORT void compile_llvm_module_to_llvm_assembly(llvm::Module &module, const std::string &filename);
EXPORT void compile_llvm_module_to_llvm(llvm::Module &module,
                                        const std::string &bitcode_filename,
                                        const std::string &llvm_assembly_filename);
// @}

}

#endif
