create or replace procedure procCalSquare(res OUT number, n IN number default 5)
IS

BEGIN
-- Arguments of a procedure may take default values.
-- The default value of a parameter is used only when the procedure is called with less number of actual parameters 
-- It is logically correct to assign default values to parameters in order RIGHT to LEFT.

--NOTE THE USE OF OUT PARAMETER TO RETURN BACK A VALUE TO THE CALLER OF PROCEDURE
   res := n *n;

END;
/