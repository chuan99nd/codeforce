.MAIN: run 
FILE_BASE_TEMPLATE = "./help_file/a.out"
BASHRC_SOURCE="/home/user/.bashrc"
run:
	export FILE_BASE_TEMPLATE=$(FILE_BASE_TEMPLATE) && g++ $(p) -o  $(FILE_BASE_TEMPLATE) && $(FILE_BASE_TEMPLATE) && printf "\n"
new:
	cp help_file/base.cpp $(p)
