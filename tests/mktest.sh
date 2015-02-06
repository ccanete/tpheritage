echo "Test ID;Return code validation;Out result;StdErr result;File creation result;Global result" >results.csv
nOk=0
nKo=0
nTotal=0
nMis=0

for i in Test*
do
  #if [ -d $i/Test* ]
  #then
  # Control will enter here if $DIRECTORY exists.
    for j in $i/Test*
    do
      if [ ! -d $j ]
      then
        break
      fi
      ./test.sh $j results.csv
      result=$?
      if [ $result -eq 0 ]
      then
        let "nKo=$nKo+1"
      elif [ $result -eq 1 ]
      then
        let "nOk=$nOk+1"
      else
        let "nMis=$nMis+1"
      fi
      let "nTotal=$nTotal+1"
    done
  #fi
  if [ -r $i/run ]
  then
    ./test.sh $i results.csv
    result=$?
    if [ $result -eq 0 ]
    then
      let "nKo=$nKo+1"
    elif [ $result -eq 1 ]
    then
      let "nOk=$nOk+1"
    else
      let "nMis=$nMis+1"
    fi
    let "nTotal=$nTotal+1"
  fi
done

echo "Passed tests     : $nOk"
echo "Failed tests     : $nKo"
echo "Misformed tests  : $nMis"
echo "-----------------------"
echo "Total            : $nTotal"
