library ieee;
use IEEE.STD_LOGIC_1164.all;

use std.textio.all;

library work;
use work.common_pack.all;

package IOFILES_PACK is

impure function file_size(path: in string) return natural;

end IOFILES_PACK;

--*****************************


package body IOFILES_PACK is
----------------------------------------
impure function file_size(path: in string) return natural is
	type char_file_t is file of character;
	variable size: natural:= 0;
	file f_handle : char_file_t;
	variable symbol: character;
begin
	file_open(f_handle, path, READ_MODE);
	while not endfile(f_handle) loop
		read(f_handle, symbol);
		size := size + 1;
	end loop;
	file_close(f_handle);
	return size;
end function file_size;
----------------------------------------
end IOFILES_PACK;
