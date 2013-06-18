#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>


/**
 * \defgroup Digital_Audio_Interface Constants for Digital Audio Interfaces
 * AES/IEC958 channel status bits.
 * \{
 */

#define IEC958_AES0_PROFESSIONAL	(1<<0)	/**< 0 = consumer, 1 = professional */
#define IEC958_AES0_NONAUDIO		(1<<1)	/**< 0 = audio, 1 = non-audio */
#define IEC958_AES0_PRO_EMPHASIS	(7<<2)	/**< mask - emphasis */
#define IEC958_AES0_PRO_EMPHASIS_NOTID	(0<<2)	/**< emphasis not indicated */
#define IEC958_AES0_PRO_EMPHASIS_NONE	(1<<2)	/**< no emphasis */
#define IEC958_AES0_PRO_EMPHASIS_5015	(3<<2)	/**< 50/15us emphasis */
#define IEC958_AES0_PRO_EMPHASIS_CCITT	(7<<2)	/**< CCITT J.17 emphasis */
#define IEC958_AES0_PRO_FREQ_UNLOCKED	(1<<5)	/**< source sample frequency: 0 = locked, 1 = unlocked */
#define IEC958_AES0_PRO_FS		(3<<6)	/**< mask - sample frequency */
#define IEC958_AES0_PRO_FS_NOTID	(0<<6)	/**< fs not indicated */
#define IEC958_AES0_PRO_FS_44100	(1<<6)	/**< 44.1kHz */
#define IEC958_AES0_PRO_FS_48000	(2<<6)	/**< 48kHz */
#define IEC958_AES0_PRO_FS_32000	(3<<6)	/**< 32kHz */
#define IEC958_AES0_CON_NOT_COPYRIGHT	(1<<2)	/**< 0 = copyright, 1 = not copyright */
#define IEC958_AES0_CON_EMPHASIS	(7<<3)	/**< mask - emphasis */
#define IEC958_AES0_CON_EMPHASIS_NONE	(0<<3)	/**< no emphasis */
#define IEC958_AES0_CON_EMPHASIS_5015	(1<<3)	/**< 50/15us emphasis */
#define IEC958_AES0_CON_MODE		(3<<6)	/**< mask - mode */
#define IEC958_AES1_PRO_MODE		(15<<0)	/**< mask - channel mode */
#define IEC958_AES1_PRO_MODE_NOTID	(0<<0)	/**< mode not indicated */
#define IEC958_AES1_PRO_MODE_STEREOPHONIC (2<<0) /**< stereophonic - ch A is left */
#define IEC958_AES1_PRO_MODE_SINGLE	(4<<0)	/**< single channel */
#define IEC958_AES1_PRO_MODE_TWO	(8<<0)	/**< two channels */
#define IEC958_AES1_PRO_MODE_PRIMARY	(12<<0)	/**< primary/secondary */
#define IEC958_AES1_PRO_MODE_BYTE3	(15<<0)	/**< vector to byte 3 */
#define IEC958_AES1_PRO_USERBITS	(15<<4)	/**< mask - user bits */
#define IEC958_AES1_PRO_USERBITS_NOTID	(0<<4)	/**< user bits not indicated */
#define IEC958_AES1_PRO_USERBITS_192	(8<<4)	/**< 192-bit structure */
#define IEC958_AES1_PRO_USERBITS_UDEF	(12<<4)	/**< user defined application */
#define IEC958_AES1_CON_CATEGORY	0x7f	/**< consumer category */
#define IEC958_AES1_CON_GENERAL		0x00	/**< general category */
#define IEC958_AES1_CON_LASEROPT_MASK	0x07	/**< Laser-optical mask */
#define IEC958_AES1_CON_LASEROPT_ID	0x01	/**< Laser-optical ID */
#define IEC958_AES1_CON_IEC908_CD	(IEC958_AES1_CON_LASEROPT_ID|0x00)	/**< IEC958 CD compatible device */
#define IEC958_AES1_CON_NON_IEC908_CD	(IEC958_AES1_CON_LASEROPT_ID|0x08)	/**< non-IEC958 CD compatible device */
#define IEC958_AES1_CON_MINI_DISC	(IEC958_AES1_CON_LASEROPT_ID|0x48)	/**< Mini-Disc device */
#define IEC958_AES1_CON_DVD		(IEC958_AES1_CON_LASEROPT_ID|0x18)	/**< DVD device */
#define IEC958_AES1_CON_LASTEROPT_OTHER	(IEC958_AES1_CON_LASEROPT_ID|0x78)	/**< Other laser-optical product */
#define IEC958_AES1_CON_DIGDIGCONV_MASK 0x07	/**< digital<->digital converter mask */
#define IEC958_AES1_CON_DIGDIGCONV_ID	0x02	/**< digital<->digital converter id */
#define IEC958_AES1_CON_PCM_CODER	(IEC958_AES1_CON_DIGDIGCONV_ID|0x00)	/**< PCM coder */
#define IEC958_AES1_CON_MIXER		(IEC958_AES1_CON_DIGDIGCONV_ID|0x10)	/**< Digital signal mixer */
#define IEC958_AES1_CON_RATE_CONVERTER	(IEC958_AES1_CON_DIGDIGCONV_ID|0x18)	/**< Rate converter */
#define IEC958_AES1_CON_SAMPLER		(IEC958_AES1_CON_DIGDIGCONV_ID|0x20)	/**< PCM sampler */
#define IEC958_AES1_CON_DSP		(IEC958_AES1_CON_DIGDIGCONV_ID|0x28)	/**< Digital sound processor */
#define IEC958_AES1_CON_DIGDIGCONV_OTHER (IEC958_AES1_CON_DIGDIGCONV_ID|0x78)	/**< Other digital<->digital product */
#define IEC958_AES1_CON_MAGNETIC_MASK	0x07	/**< Magnetic device mask */
#define IEC958_AES1_CON_MAGNETIC_ID	0x03	/**< Magnetic device ID */
#define IEC958_AES1_CON_DAT		(IEC958_AES1_CON_MAGNETIC_ID|0x00)	/**< Digital Audio Tape */
#define IEC958_AES1_CON_VCR		(IEC958_AES1_CON_MAGNETIC_ID|0x08)	/**< Video recorder */
#define IEC958_AES1_CON_DCC		(IEC958_AES1_CON_MAGNETIC_ID|0x40)	/**< Digital compact cassette */
#define IEC958_AES1_CON_MAGNETIC_DISC	(IEC958_AES1_CON_MAGNETIC_ID|0x18)	/**< Magnetic disc digital audio device */
#define IEC958_AES1_CON_MAGNETIC_OTHER	(IEC958_AES1_CON_MAGNETIC_ID|0x78)	/**< Other magnetic device */
#define IEC958_AES1_CON_BROADCAST1_MASK 0x07	/**< Broadcast mask */
#define IEC958_AES1_CON_BROADCAST1_ID	0x04	/**< Broadcast ID */
#define IEC958_AES1_CON_DAB_JAPAN	(IEC958_AES1_CON_BROADCAST1_ID|0x00)	/**< Digital audio broadcast (Japan) */
#define IEC958_AES1_CON_DAB_EUROPE	(IEC958_AES1_CON_BROADCAST1_ID|0x08)	/**< Digital audio broadcast (Europe) */
#define IEC958_AES1_CON_DAB_USA		(IEC958_AES1_CON_BROADCAST1_ID|0x60)	/**< Digital audio broadcast (USA) */
#define IEC958_AES1_CON_SOFTWARE	(IEC958_AES1_CON_BROADCAST1_ID|0x40)	/**< Electronic software delivery */
#define IEC958_AES1_CON_IEC62105	(IEC958_AES1_CON_BROADCAST1_ID|0x20)	/**< Used by another standard (IEC 62105) */
#define IEC958_AES1_CON_BROADCAST1_OTHER (IEC958_AES1_CON_BROADCAST1_ID|0x78)	/**< Other broadcast product */
#define IEC958_AES1_CON_BROADCAST2_MASK 0x0f	/**< Broadcast alternative mask */
#define IEC958_AES1_CON_BROADCAST2_ID	0x0e	/**< Broadcast alternative ID */
#define IEC958_AES1_CON_MUSICAL_MASK	0x07	/**< Musical device mask */
#define IEC958_AES1_CON_MUSICAL_ID	0x05	/**< Musical device ID */
#define IEC958_AES1_CON_SYNTHESIZER	(IEC958_AES1_CON_MUSICAL_ID|0x00)	/**< Synthesizer */
#define IEC958_AES1_CON_MICROPHONE	(IEC958_AES1_CON_MUSICAL_ID|0x08)	/**< Microphone */
#define IEC958_AES1_CON_MUSICAL_OTHER	(IEC958_AES1_CON_MUSICAL_ID|0x78)	/**< Other musical device */
#define IEC958_AES1_CON_ADC_MASK	0x1f	/**< ADC Mask */
#define IEC958_AES1_CON_ADC_ID		0x06	/**< ADC ID */
#define IEC958_AES1_CON_ADC		(IEC958_AES1_CON_ADC_ID|0x00)	/**< ADC without copyright information */
#define IEC958_AES1_CON_ADC_OTHER	(IEC958_AES1_CON_ADC_ID|0x60)	/**< Other ADC product (with no copyright information) */
#define IEC958_AES1_CON_ADC_COPYRIGHT_MASK 0x1f	/**< ADC Copyright mask */
#define IEC958_AES1_CON_ADC_COPYRIGHT_ID 0x16	/**< ADC Copyright ID */
#define IEC958_AES1_CON_ADC_COPYRIGHT	(IEC958_AES1_CON_ADC_COPYRIGHT_ID|0x00)	/**< ADC with copyright information */
#define IEC958_AES1_CON_ADC_COPYRIGHT_OTHER (IEC958_AES1_CON_ADC_COPYRIGHT_ID|0x60)	/**< Other ADC with copyright information product */
#define IEC958_AES1_CON_SOLIDMEM_MASK	0x0f	/**< Solid memory based products mask */
#define IEC958_AES1_CON_SOLIDMEM_ID	0x08	/**< Solid memory based products ID */
#define IEC958_AES1_CON_SOLIDMEM_DIGITAL_RECORDER_PLAYER (IEC958_AES1_CON_SOLIDMEM_ID|0x00)	/**< Digital audio recorder and player using solid state memory */
#define IEC958_AES1_CON_SOLIDMEM_OTHER	(IEC958_AES1_CON_SOLIDMEM_ID|0x70)	/**< Other solid state memory based product */
#define IEC958_AES1_CON_EXPERIMENTAL	0x40	/**< experimental category */
#define IEC958_AES1_CON_ORIGINAL	(1<<7)	/**< this bits depends on the category code */
#define IEC958_AES2_PRO_SBITS		(7<<0)	/**< mask - sample bits */
#define IEC958_AES2_PRO_SBITS_20	(2<<0)	/**< 20-bit - coordination */
#define IEC958_AES2_PRO_SBITS_24	(4<<0)	/**< 24-bit - main audio */
#define IEC958_AES2_PRO_SBITS_UDEF	(6<<0)	/**< user defined application */
#define IEC958_AES2_PRO_WORDLEN		(7<<3)	/**< mask - source word length */
#define IEC958_AES2_PRO_WORDLEN_NOTID	(0<<3)	/**< source word length not indicated */
#define IEC958_AES2_PRO_WORDLEN_22_18	(2<<3)	/**< 22-bit or 18-bit */
#define IEC958_AES2_PRO_WORDLEN_23_19	(4<<3)	/**< 23-bit or 19-bit */
#define IEC958_AES2_PRO_WORDLEN_24_20	(5<<3)	/**< 24-bit or 20-bit */
#define IEC958_AES2_PRO_WORDLEN_20_16	(6<<3)	/**< 20-bit or 16-bit */
#define IEC958_AES2_CON_SOURCE		(15<<0)	/**< mask - source number */
#define IEC958_AES2_CON_SOURCE_UNSPEC	(0<<0)	/**< source number unspecified */
#define IEC958_AES2_CON_CHANNEL		(15<<4)	/**< mask - channel number */
#define IEC958_AES2_CON_CHANNEL_UNSPEC	(0<<4)	/**< channel number unspecified */
#define IEC958_AES3_CON_FS		(15<<0)	/**< mask - sample frequency */
#define IEC958_AES3_CON_FS_44100	(0<<0)	/**< 44.1kHz */
#define IEC958_AES3_CON_FS_NOTID	(1<<0)	/**< sample frequency non indicated */
#define IEC958_AES3_CON_FS_48000	(2<<0)	/**< 48kHz */
#define IEC958_AES3_CON_FS_32000	(3<<0)	/**< 32kHz */
#define IEC958_AES3_CON_FS_22050	(4<<0)	/**< 22.05kHz */
#define IEC958_AES3_CON_FS_24000	(6<<0)	/**< 24kHz */
#define IEC958_AES3_CON_FS_88200	(8<<0)	/**< 88.2kHz */
#define IEC958_AES3_CON_FS_768000	(9<<0)	/**< 768kHz */
#define IEC958_AES3_CON_FS_96000	(10<<0)	/**< 96kHz */
#define IEC958_AES3_CON_FS_176400	(12<<0)	/**< 176.4kHz */
#define IEC958_AES3_CON_FS_192000	(14<<0)	/**< 192kHz */
#define IEC958_AES3_CON_CLOCK		(3<<4)	/**< mask - clock accuracy */
#define IEC958_AES3_CON_CLOCK_1000PPM	(0<<4)	/**< 1000 ppm */
#define IEC958_AES3_CON_CLOCK_50PPM	(1<<4)	/**< 50 ppm */
#define IEC958_AES3_CON_CLOCK_VARIABLE	(2<<4)	/**< variable pitch */
#define IEC958_AES4_CON_MAX_WORDLEN_24	(1<<0)	/**< 0 = 20-bit, 1 = 24-bit */
#define IEC958_AES4_CON_WORDLEN		(7<<1)	/**< mask - sample word length */
#define IEC958_AES4_CON_WORDLEN_NOTID	(0<<1)	/**< not indicated */
#define IEC958_AES4_CON_WORDLEN_20_16	(1<<1)	/**< 20-bit or 16-bit */
#define IEC958_AES4_CON_WORDLEN_22_18	(2<<1)	/**< 22-bit or 18-bit */
#define IEC958_AES4_CON_WORDLEN_23_19	(4<<1)	/**< 23-bit or 19-bit */
#define IEC958_AES4_CON_WORDLEN_24_20	(5<<1)	/**< 24-bit or 20-bit */
#define IEC958_AES4_CON_WORDLEN_21_17	(6<<1)	/**< 21-bit or 17-bit */
#define IEC958_AES4_CON_ORIGFS		(15<<4)	/**< mask - original sample frequency */
#define IEC958_AES4_CON_ORIGFS_NOTID	(0<<4)	/**< original sample frequency not indicated */
#define IEC958_AES4_CON_ORIGFS_192000	(1<<4)	/**< 192kHz */
#define IEC958_AES4_CON_ORIGFS_12000	(2<<4)	/**< 12kHz */
#define IEC958_AES4_CON_ORIGFS_176400	(3<<4)	/**< 176.4kHz */
#define IEC958_AES4_CON_ORIGFS_96000	(5<<4)	/**< 96kHz */
#define IEC958_AES4_CON_ORIGFS_8000	(6<<4)	/**< 8kHz */
#define IEC958_AES4_CON_ORIGFS_88200	(7<<4)	/**< 88.2kHz */
#define IEC958_AES4_CON_ORIGFS_16000	(8<<4)	/**< 16kHz */
#define IEC958_AES4_CON_ORIGFS_24000	(9<<4)	/**< 24kHz */
#define IEC958_AES4_CON_ORIGFS_11025	(10<<4)	/**< 11.025kHz */
#define IEC958_AES4_CON_ORIGFS_22050	(11<<4)	/**< 22.05kHz */
#define IEC958_AES4_CON_ORIGFS_32000	(12<<4)	/**< 32kHz */
#define IEC958_AES4_CON_ORIGFS_48000	(13<<4)	/**< 48kHz */
#define IEC958_AES4_CON_ORIGFS_44100	(15<<4)	/**< 44.1kHz */
#define IEC958_AES5_CON_CGMSA		(3<<0)	/**< mask - CGMS-A */
#define IEC958_AES5_CON_CGMSA_COPYFREELY (0<<0)	/**< copying is permitted without restriction */
#define IEC958_AES5_CON_CGMSA_COPYONCE	(1<<0)	/**< one generation of copies may be made */
#define IEC958_AES5_CON_CGMSA_COPYNOMORE (2<<0)	/**< condition not be used */
#define IEC958_AES5_CON_CGMSA_COPYNEVER	(3<<0)	/**< no copying is permitted */

/** \} */

	unsigned int counter;
	unsigned int channel;
	unsigned char status[24];
	unsigned char preamble[3] = {8,2,4};	/* B/M/W or Z/X/Y */
	unsigned int previous_bit;

//	# As default, Z = 0x08, Y = 0x04, X = 0x02
enum { PREAMBLE_Z, PREAMBLE_X, PREAMBLE_Y };

static unsigned char snd_pcm_bmc_preambles[] = {    0b00000000, //
                                                    0b00000000, //
                                                    0b11100010, // X
                                                    0b00000000, //
                                                    0b11100100, // Y
                                                    0b00000000, //
                                                    0b00000000, //
                                                    0b00000000, //
                                                    0b11101000, // Z
                                                    0b00000000, //
                                                    0b00000000, //
                                                    0b00000000, //
                                                    0b00000000, //
                                                    0b00000000, //
                                                    0b00000000, //
                                                    0b00000000, //
                                               };


static unsigned int iec958_parity(unsigned int data)
{
	unsigned int parity;
	int bit;

	data >>= 4;     /* start from bit 4 */
	parity = 0;
	for (bit = 4; bit <= 30; bit++) {
		if (data & 1)
			parity++;
		data >>= 1;
	}
	return (parity & 1);
}

static inline uint32_t iec958_subframe(uint32_t data, int channel)
{
	unsigned int byte = counter >> 3;
	unsigned int mask = 1 << (counter - (byte << 3));

	/* bit 4-27 */
	data >>= 4;
	data &= ~0xf;

	/* set IEC status bits (up to 192 bits) */
	if (status[byte] & mask)
		data |= 0x40000000;

	if (iec958_parity(data))	/* parity bit 4-30 */
		data |= 0x80000000;

	/* Preamble */
	if (channel)
		data |= preamble[PREAMBLE_Y];	/* odd sub frame, 'Y' */
	else if (! counter)
		data |= preamble[PREAMBLE_Z];	/* Block start, 'Z' */
	else
		data |= preamble[PREAMBLE_X];	/* even sub frame, 'X' */

//	if (iec->byteswap)
//		data = bswap_32(data);

	return data;
}

static uint32_t iec958_encode( uint32_t sample )
{
    uint32_t value;

    value = iec958_subframe(sample, channel);

    channel++;
    channel = channel % 2;

    counter++;
    counter %= 192;

    return value;
}

static uint64_t bmc_magic(uint32_t sample)
{
    int64_t value = 0;
    unsigned char preamble;
    int8_t i;

    /* if last bit of previous block was 1, invert preamble */
    if( previous_bit == 0 )
        preamble = snd_pcm_bmc_preambles[sample & 0xF];
    else
        preamble = ~snd_pcm_bmc_preambles[sample & 0xF];

    /* Remember the last bit for next block */
    if( sample & 0x80000000 )
        previous_bit = 1;
    else
        previous_bit = 0;

    /* first, get&set preamble */
    value |= preamble;
    sample >>= 4;

    /* then, loop through rest of the data */
    for( i = 0; i < 28; i++ )
    {
        uint32_t bit  = ( sample >> i ) & 1;
        uint32_t prev = value & 1;
        value <<= 2;

        if( bit == 1 )
            if( prev == 0 )
                value |= 2;
            else
                value |= 1;
        else
            if( prev == 0 )
                value |= 3;
            else
                value |= 0;
    }

    /* BCM2835-ARM-Peripherals.pdf:
     * "Note that data is always serialised MS-bit first. This is well-established
     *  behaviour in both PCM and I2S."
     *
     * pcm_iec958.c says that preamble is at LSB ... Because of this, the bit ordering
     * is reversed here while performing bmc encoding..
     */

    return value;
}

int main( void )
{
    FILE *fo, *fi;
    uint8_t  encoded[8];
    uint64_t *ptr = (uint64_t*)&encoded;
    uint32_t sample;

	static const unsigned char default_status_bits[] = {
		IEC958_AES0_CON_NOT_COPYRIGHT,
		0,
		0,
		IEC958_AES3_CON_FS_44100,
		IEC958_AES4_CON_WORDLEN_20_16
	};
// Status bits: all cleared, seem to work! (uncomment next line if need to change)
//	memcpy(status, default_status_bits, sizeof(default_status_bits));

    /* Open files */
    fi = stdin;
    fo = stdout;

    /* Do the conversion */
    while ( fread(&sample, 4, 1, fi) )
    {
        *ptr = bmc_magic( iec958_encode( sample ) );

        // need to reverse channel order.
        fwrite(&encoded[4], 4, 1, fo);
        fwrite(&encoded[0], 4, 1, fo);
    }

    /* Close files */
    fclose(fi);
    fclose(fo);
}


