void bspConsoleDumpMemory(uint8_t *buffer, uint32_t size)
{
	uint32_t i, j;
	uint32_t last_line_start;
	uint8_t *tmp;

	for (i = 0; i < (size / 16); i++)
	{
		tmp = (uint8_t *) & buffer[i * 16];
		for (j = 0; j < 4; j++)
		{
			putnum( tmp[0]); putnum(tmp[1]); putnum(tmp[2]); putnum(tmp[3]);
//			printf("%02X %02X %02X %02X ", tmp[0], tmp[1], tmp[2], tmp[3]);
			tmp += 4;
		}
		printf("\r\n");
	}

	if ((size % 16) != 0)
	{
		last_line_start = size - (size % 16);
		for (j = last_line_start; j < last_line_start + 16; j++)
		{
			if ((j != last_line_start) && (j % 4 == 0))
			{
				print(" ");
			}
			if (j < size)
				putnum(buffer[j]);
			else
				print("  ");
		}
		print("\r\n");
	}
}

