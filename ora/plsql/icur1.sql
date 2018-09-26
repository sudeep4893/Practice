BEGIN
  --A demo of implicit cursor

  update emp set esal = esal + 1;  
  --a SQL statement written in a PLSQL block
  -- it forms an "implicit cursor"

  --Here check the cursor attributes 
  DBMS_OUTPUT.PUT_LINE(SQL%ROWCOUNT || ' rows updated');
  
  IF SQL%ISOPEN THEN
     DBMS_OUTPUT.PUT_LINE('implicit cursor is open');
  ELSE
     DBMS_OUTPUT.PUT_LINE('implicit cursor is closed');
  END IF;
END;
/