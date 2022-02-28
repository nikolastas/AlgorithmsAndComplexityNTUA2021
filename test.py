from subprocess import PIPE, Popen
import time

timeoutInSeconds = 1
inputfolder=input()
inputnumber=int(input())
for n in range(1,inputnumber):
    inputFile = f'{inputfolder}/input{n}.txt'
    outputFile = f'{inputfolder}/output{n}.txt'
    f = open(outputFile)
    output = f.read()
    command = "time ./a.out < " + inputFile
    process = Popen(command, shell=True, stdout=PIPE, stderr=PIPE)

    timeStarted = time.time()                                 # Save start time.

    cmdTimer     =  "sleep "+str(timeoutInSeconds)            # Waiting for timeout...
    cmdKill      =  "kill -SIGTERM "+str(process.pid)+" 2>/dev/null"   # And killing process.
    cmdTimeout   =  cmdTimer+" && "+cmdKill                   # Combine commands above.
    procTimeout  =  Popen(cmdTimeout,shell=True)   
    producedOutput, err = process.communicate()
    
    timediff = time.time() - timeStarted

    if output == producedOutput.decode("utf-8"):
        print(f'+++ Testcase {n} passed!', f' with time :', timediff)
    else:
        print(f"'--- Testcase {n} failed!'")
        print(f'Expected Output:\n{output}')
        print(f'Produced Output:\n{producedOutput.decode("utf-8")}')