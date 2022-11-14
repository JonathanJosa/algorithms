defmodule Omega do
  def euclides(n, 0), do: IO.puts n
  def euclides(n, m), do: euclides(m, rem(n, m))
end
