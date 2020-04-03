----------------------------------------------------------------------------------
-- Company: ENSEA
-- Student: Paul Wysocki
--
-- Create Date:    20/03/20
-- Project Name: TP SoC
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_arith.ALL;
use IEEE.STD_LOGIC_unsigned.ALL;
    
	 
ENTITY HdwTPSoc IS
  Port ( --MonReset : in STD_LOGIC;
         KEY : in std_logic_vector(3 downto 0);	--Nomage par défaut des pin dans le fichier .tcl
			MaClock : in std_logic;
			--s7seg   : out std_logic_vector(47 downto 0);	--Nomage par défaut des pin dans le fichier .tcl
			HEX0 : out std_logic_vector(6 downto 0);
			HEX1 : out std_logic_vector(6 downto 0);
			HEX2 : out std_logic_vector(6 downto 0);
			HEX3 : out std_logic_vector(6 downto 0);
			HEX4 : out std_logic_vector(6 downto 0);
			HEX5 : out std_logic_vector(6 downto 0)
			);
END HdwTPSoc;

Architecture HdwTPSocArchi OF HdwTPSoc IS

    component SysHdwTP is
        port (
            bp1_export    : in  std_logic                     := 'X'; -- export
				clk_clk       : in  std_logic                     := 'X'; -- clk
            s7seg_export  : out std_logic_vector(47 downto 0);        -- export
            reset_reset_n : in  std_logic                     := 'X'  -- reset_n
        );
    end component SysHdwTP;

	signal hex : std_logic_vector (47 downto 0);		--On créait un signal externe pour "dispatcher" les signaux entre les 7Seg
BEGIN
	 
	 
    u0 : component SysHdwTP
        port map (
            clk_clk       => MaClock,
            --s7seg_export  => s7seg,
				s7seg_export  => hex,			-- version en utilisant le nom de signaux du ficheir .tcl
            --reset_reset_n => MonReset
				reset_reset_n => KEY(0),		-- version en utilisant le nom de signaux du ficheir .tcl
				bp1_export    => KEY(1)   --   bp1.export
        );
		  
		  HEX0 <= hex(6 downto 0);
        HEX1 <= hex(14 downto 8);
        HEX2 <= hex(22 downto 16);
        HEX3 <= hex(30 downto 24);
        HEX4 <= hex(38 downto 32);
        HEX5 <= hex(46 downto 40);
		  

END HdwTPSocArchi;


-- Nouveau ----------------------------------------------------------

