################################################
# 	COMPILER AND COMPILE FLAG SETTINGS
################################################
CXX	= g++
INC_FLAGS = -I. 
CXXFLAGS = -O0 -g3 -Wall -Wno-deprecated $(INC_FLAGS)

################################################
# 	SOURCE and OBJECT FILES
################################################
# Add inputs and outputs from these tool invocations to the build variables 
OBJS += \
./obj/Image.o \
./obj/ImageIO.o 

CPP_DEPS += $(OBJS:.o=.d)

# General rule to generate .o files from .cpp files
obj/%.o: src/%.cpp
	@echo 'Building file: $<'
	$(CXX) $(CXXFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c $< -o $@
	@echo 'Finished building: $<'
	@echo ' '

################################################
# 	MAKE TARGETS
################################################

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: MIPImageIO

# Tool invocations
MIP%: ./obj/MIP%.o $(OBJS)
	@echo 'Building target: $@'
	$(CXX) -o "./bin/$@" ./obj/$@.o $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	
# Other Targets
clean:
	rm -rf ./bin/MIP* ./obj/*.d ./obj/*.o
	@echo ' '

ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
