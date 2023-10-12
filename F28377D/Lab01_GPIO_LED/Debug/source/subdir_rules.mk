################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
source/%.obj: ../source/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/CCS9.2/ccs/tools/compiler/ti-cgt-c2000_20.2.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="D:/ti/CCS9.2/28377YT/Lab01_GPIO_LED" --include_path="D:/ti/CCS9.2/28377YT/Lab01_GPIO_LED/include" --include_path="D:/ti/CCS9.2/ccs/tools/compiler/ti-cgt-c2000_20.2.3.LTS/include" --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

source/%.obj: ../source/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/CCS9.2/ccs/tools/compiler/ti-cgt-c2000_20.2.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="D:/ti/CCS9.2/28377YT/Lab01_GPIO_LED" --include_path="D:/ti/CCS9.2/28377YT/Lab01_GPIO_LED/include" --include_path="D:/ti/CCS9.2/ccs/tools/compiler/ti-cgt-c2000_20.2.3.LTS/include" --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


