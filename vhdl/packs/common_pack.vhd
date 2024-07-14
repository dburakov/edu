library IEEE;
use IEEE.STD_LOGIC_1164.all;
use ieee.std_logic_arith.all;

package common_pack is

--types
subtype std_byte_t is std_logic_vector(7 downto 0);

--functions
function ByteToStd(ivalue: in character) return std_byte_t;
function log2(ivalue: in positive) return natural;

end common_pack;


package body common_pack is
----------------------------------------
function log2(ivalue: in positive) return natural is
	variable ret: natural;
	variable x: positive;
begin
	ret := 0;
	x := 1;
	while ivalue > x loop
		x := x*2;
		ret := ret + 1;
	end loop;
	return ret;
end function log2;
----------------------------------------
----------------------------------------
function ByteToStd(ivalue: in character) return std_byte_t is
	variable ret: std_byte_t;
begin
	ret := CONV_STD_LOGIC_VECTOR(character'pos(ivalue),8);
	return ret;
end function ByteToStd;
---------------------------------------- 
end common_pack;
