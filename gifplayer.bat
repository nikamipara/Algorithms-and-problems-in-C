echo "Please enter some input: "
set /p input_variable=
echo "You entered: %input_variable%"
del abc.txt
java -classpath "D:\DropBox\experiments" filelist %input_variable%>>abc.txt
set /p var= <abc.txt
start chrome %var%