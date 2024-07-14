----------------------------------------------------------------------------------
-- Company:  
-- Engineer: M.M. Rodionov 
-- Create Date:    20:38:54 02/24/2012 
-- Module Name:    DATA_GENERATOR - Behavioral 
-- Description: 	The DATA_GENERATOR block formate output data stream
--						corresponding to file.bin content.
--Featches:
-- Mode of data storage - BIG_ENDIAN
-- File size must be a multiple of the gWSIZE value

--Usage:
--* * * * * * * * * * * * * * * * * * * *
--* 
--*
--* * * * * * * * * * * * * * * * * * * *

-- Revision: 
-- Revision 0.01 - File Created
-- Revision 1.01 - Module was complete
----------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use std.textio.all;

library work;
use work.iofiles_pack.all;
use work.common_pack.all;

entity DATA_GENERATOR is
	Generic( gFPATH: string := "file.bin";--path to file name
				gWSIZE: natural range 1 to 16 := 1);-- byte size of output bus
				
    Port ( EN : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
			  EOF : out STD_LOGIC:='0';--End Of File signal equal '1' when read last word
           DATA_OUT : out  STD_LOGIC_VECTOR (gWSIZE*8-1 downto 0):=(others =>'0'));
end DATA_GENERATOR;

architecture Behavioral of DATA_GENERATOR is

constant cWORD_NUM: natural := file_size(gFPATH)/gWSIZE;
constant cADDR_LEN: natural := log2(cWORD_NUM);

subtype word_t is std_logic_vector(8*gWSIZE-1 downto 0);
type rom_t is array(0 to cWORD_NUM-1) of word_t; 


--function to read cWORD_NUM words to array of std_logic_vector
impure function read_to_rom (path : in string) return rom_t is                                                   
	type file_t is file of character;
	file file_handle : file_t;                       
	variable symbol : character;                                 
	variable rom_array : rom_t;
begin
	--Open file
	file_open(file_handle, path, READ_MODE);
   
	--Main reading loop
	for i in 0 to cWORD_NUM-1 loop
		for j in 1 to gWSIZE loop
			read(file_handle, symbol);
			rom_array(i)(8*j-1 downto 8*(j-1)) := ByteToStd(symbol);
		end loop;
	end loop;
	
	--Close file
	file_close(file_handle);
	return rom_array;                                                  
end function;                                                
 

signal rom : rom_t:= read_to_rom(gFPATH);
signal address: std_logic_vector(cADDR_LEN-1 downto 0) := (others=>'0');
begin

process(CLK)
begin
	if rising_edge(CLK) then
		if RESET = '1' then
			EOF <= '0';
			address <= (others => '0');
			DATA_OUT <= (others => '0');
		elsif EN = '1' then
			
			-- address counter
			if address < (cWORD_NUM-1) then
				address <= address + 1;
			else
				address <= (others=>'0');
			end if;
			
			--read from rom array
			DATA_OUT <= rom(conv_integer(address));
			
			-- end of file strobe
			if address = cWORD_NUM-1 then
				EOF <= '1';
			else
				EOF <= '0';
			end if;
		end if;
	end if;
end process;


end Behavioral;

