	component SysHdwTP is
		port (
			bp1_export    : in  std_logic                     := 'X'; -- export
			clk_clk       : in  std_logic                     := 'X'; -- clk
			reset_reset_n : in  std_logic                     := 'X'; -- reset_n
			s7seg_export  : out std_logic_vector(47 downto 0)         -- export
		);
	end component SysHdwTP;

	u0 : component SysHdwTP
		port map (
			bp1_export    => CONNECTED_TO_bp1_export,    --   bp1.export
			clk_clk       => CONNECTED_TO_clk_clk,       --   clk.clk
			reset_reset_n => CONNECTED_TO_reset_reset_n, -- reset.reset_n
			s7seg_export  => CONNECTED_TO_s7seg_export   -- s7seg.export
		);

