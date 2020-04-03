
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

----- avalon MM s1 slave (read/write)
entity 	seg7_if is
	--  Parameter Declarations  
	generic(SEG7_NUM : integer := 4;
			ADDR_WIDTH : integer :=	2;		
			DEFAULT_ACTIVE : integer := 1;
			LOW_ACTIVE : integer := 1);
			-- Port Declarations
	port (  avs_s1_clk : in STD_LOGIC;		
			avs_s1_address : in STD_LOGIC_VECTOR(ADDR_WIDTH-1 downto 0);
			avs_s1_read : in STD_LOGIC;
			avs_s1_readdata : out STD_LOGIC_VECTOR(7 downto 0);
			avs_s1_write : in STD_LOGIC;
			avs_s1_writedata : in STD_LOGIC_VECTOR(7 downto 0);
			avs_s1_reset : in STD_LOGIC;

			-- avalon MM s1 to export (read, read/write, Interface to export
			avs_s1_export_seg7 : out STD_LOGIC_VECTOR(SEG7_NUM*8-1 downto 0)
); end seg7_if;
	
architecture A of seg7_if is
	-- Internal Wire/Register
	signal reg_file : STD_LOGIC_VECTOR(SEG7_NUM*8-1 downto 0);
	signal read_data : STD_LOGIC_VECTOR(7 downto 0);	
begin -- Sequence logic
	seq : process (avs_s1_clk)
		variable base_index : integer range (SEG7_NUM*8-1) downto 0;
		variable write_data : STD_LOGIC_VECTOR(7 downto 0);
	begin
		if avs_s1_clk'event and avs_s1_clk = '0' then
			if (avs_s1_reset = '1') then
				if (DEFAULT_ACTIVE = 1) then -- turn on or off
					reg_file <= (others => '1');
				else 
					reg_file <= (others => '0');
				end if;
	
			elsif (avs_s1_write = '1') then
				write_data := avs_s1_writedata;
				base_index := conv_integer(avs_s1_address & "000");
				reg_file(base_index+7 downto base_index) <= write_data;
						
			elsif (avs_s1_read = '1') then
				base_index := conv_integer(avs_s1_address & "000");
				read_data <= reg_file(base_index+7 downto base_index);
			end	if;
		end if;
	end process seq;
	
	-- Combinational logic
	avs_s1_export_seg7 <= (not reg_file) when (LOW_ACTIVE = 1) else reg_file;
	avs_s1_readdata <= read_data;

end A;
