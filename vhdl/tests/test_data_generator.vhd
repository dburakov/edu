--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY test_rom IS
END test_rom;
 
ARCHITECTURE behavior OF test_rom IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT DATA_GENERATOR
    Generic( gFPATH: string := "C:\read2.dat";--path to file name
				gWSIZE: natural range 1 to 16 := 1);-- byte size of output bus
				
    Port ( EN : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
			  EOF : out STD_LOGIC;--End Of File signal equal '1' when read last word
           DATA_OUT : out  STD_LOGIC_VECTOR (gWSIZE*8-1 downto 0));
    END COMPONENT;
    

   --Inputs
	constant cWSIZE: natural := 4;
   signal EN : std_logic := '0';
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';

 	--Outputs
   signal EOF : std_logic;
   signal DATA_OUT : std_logic_vector(8*cWSIZE-1 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: DATA_GENERATOR 
	generic map(gFPATH => "C:\read2.dat", gWSIZE => cWSIZE)
	port map (
          EN => EN,
          CLK => CLK,
          RESET => RESET,
          EOF => EOF,
          DATA_OUT => DATA_OUT
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CLK_period*10;
		EN <= '1';
      -- insert stimulus here 
		wait for CLK_period*45;
		RESET <= '1';
		wait for CLK_period*4;
		RESET <= '0';
      wait;
   end process;

END;
