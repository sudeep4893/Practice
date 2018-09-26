create or replace procedure toggleCase(x IN OUT varchar)
IS
len number;
i number;
orig varchar(1);
togg varchar(1);
result varchar(30);

BEGIN
-- An IN OUT qualifier for a parameter makes the parameter readable as well as writable for the procedure

  result := '';
  len := length(x); 
  for i in 1..len
  LOOP
    orig := substr(x, i, 1); -- char at index i
    IF orig >= 'A' AND orig <= 'Z' THEN
      togg := lower(orig);
    ELSIF orig >= 'a' AND orig <= 'z' THEN
      togg := upper(orig);    
    END IF;

    result := result || togg;    
  END LOOP;

  x:= result;  
END;
/
