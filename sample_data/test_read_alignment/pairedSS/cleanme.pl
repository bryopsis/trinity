#!/usr/bin/env perl

use strict;
use warnings;

use FindBin;


## we delete all files we don't need in this directory. Be careful in case users try running it somewhere else, outside this dir.
chdir $FindBin::Bin or die "error, cannot cd to $FindBin::Bin";



my @files_to_keep = qw ( cleanme.pl 
                       top100k.reads.senseOrient.fa.gz
top100k.genes.gff3.gz
top100k.bam
top100k.genome.gz
top100k.Left.fq.gz
top100k.Right.fq.gz
run_BLAT_alignments.sh
run_bowtie_alignments_SS.sh
run_bowtie_alignments_notSS.sh
run_bwa_alignments.sh
run_tophat_alignments.sh

);


my %keep = map { + $_ => 1 } @files_to_keep;


`rm -rf BLAT_out`;
`rm -rf bowtie_out`;
`rm -rf bwa_out`;
`rm -rf tophat_out`;

foreach my $file (<*>) {
	
	if (! $keep{$file}) {
		print STDERR "-removing file: $file\n";
		unlink($file);
	}
}


exit(0);
