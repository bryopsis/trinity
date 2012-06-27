/***** This code was generated by Yaggo. Do not edit ******/

#ifndef __COUNT_ARGS_HPP__
#define __COUNT_ARGS_HPP__

#include <jellyfish/yaggo.hpp>

class count_args {
public:
  uint32_t                       mer_len_arg;
  bool                           mer_len_given;
  uint64_t                       size_arg;
  bool                           size_given;
  uint32_t                       threads_arg;
  bool                           threads_given;
  yaggo::string                  output_arg;
  bool                           output_given;
  uint32_t                       counter_len_arg;
  bool                           counter_len_given;
  uint32_t                       out_counter_len_arg;
  bool                           out_counter_len_given;
  bool                           both_strands_flag;
  uint32_t                       reprobes_arg;
  bool                           reprobes_given;
  bool                           raw_flag;
  bool                           both_flag;
  bool                           quake_flag;
  uint32_t                       quality_start_arg;
  bool                           quality_start_given;
  uint32_t                       min_quality_arg;
  bool                           min_quality_given;
  uint64_t                       lower_count_arg;
  bool                           lower_count_given;
  uint64_t                       upper_count_arg;
  bool                           upper_count_given;
  yaggo::string                  matrix_arg;
  bool                           matrix_given;
  const char *                   timing_arg;
  bool                           timing_given;
  const char *                   stats_arg;
  bool                           stats_given;
  bool                           no_write_flag;
  bool                           measure_flag;
  uint64_t                       buffers_arg;
  bool                           buffers_given;
  uint64_t                       buffer_size_arg;
  bool                           buffer_size_given;
  uint64_t                       out_buffer_size_arg;
  bool                           out_buffer_size_given;
  bool                           lock_flag;
  bool                           stream_flag;
  std::vector<const char *>      file_arg;
  typedef std::vector<const char *>::iterator file_arg_it;
  typedef std::vector<const char *>::const_iterator file_arg_const_it;

  enum {
    USAGE_OPT = 1000,
    FULL_HELP_OPT,
    OUT_COUNTER_LEN_OPT,
    BOTH_OPT,
    QUALITY_START_OPT,
    MIN_QUALITY_OPT,
    MATRIX_OPT,
    TIMING_OPT,
    STATS_OPT,
    BUFFERS_OPT,
    BUFFER_SIZE_OPT,
    OUT_BUFFER_SIZE_OPT,
    LOCK_OPT,
    STREAM_OPT
  };

  count_args(int argc, char *argv[]) :
    mer_len_arg(), mer_len_given(false),
    size_arg(), size_given(false),
    threads_arg(1), threads_given(false),
    output_arg("mer_counts"), output_given(false),
    counter_len_arg(7), counter_len_given(false),
    out_counter_len_arg(4), out_counter_len_given(false),
    both_strands_flag(false),
    reprobes_arg(62), reprobes_given(false),
    raw_flag(false),
    both_flag(false),
    quake_flag(false),
    quality_start_arg(64), quality_start_given(false),
    min_quality_arg(0), min_quality_given(false),
    lower_count_arg(), lower_count_given(false),
    upper_count_arg(), upper_count_given(false),
    matrix_arg(""), matrix_given(false),
    timing_arg(""), timing_given(false),
    stats_arg(""), stats_given(false),
    no_write_flag(false),
    measure_flag(false),
    buffers_arg(), buffers_given(false),
    buffer_size_arg(8192), buffer_size_given(false),
    out_buffer_size_arg(20000000), out_buffer_size_given(false),
    lock_flag(false),
    stream_flag(false)
  {
    static struct option long_options[] = {
      {"mer-len", 1, 0, 'm'},
      {"size", 1, 0, 's'},
      {"threads", 1, 0, 't'},
      {"output", 1, 0, 'o'},
      {"counter-len", 1, 0, 'c'},
      {"out-counter-len", 1, 0, OUT_COUNTER_LEN_OPT},
      {"both-strands", 0, 0, 'C'},
      {"reprobes", 1, 0, 'p'},
      {"raw", 0, 0, 'r'},
      {"both", 0, 0, BOTH_OPT},
      {"quake", 0, 0, 'q'},
      {"quality-start", 1, 0, QUALITY_START_OPT},
      {"min-quality", 1, 0, MIN_QUALITY_OPT},
      {"lower-count", 1, 0, 'L'},
      {"upper-count", 1, 0, 'U'},
      {"matrix", 1, 0, MATRIX_OPT},
      {"timing", 1, 0, TIMING_OPT},
      {"stats", 1, 0, STATS_OPT},
      {"no-write", 0, 0, 'w'},
      {"measure", 0, 0, 'u'},
      {"buffers", 1, 0, BUFFERS_OPT},
      {"buffer-size", 1, 0, BUFFER_SIZE_OPT},
      {"out-buffer-size", 1, 0, OUT_BUFFER_SIZE_OPT},
      {"lock", 0, 0, LOCK_OPT},
      {"stream", 0, 0, STREAM_OPT},
      {"help", 0, 0, 'h'},
      {"full-help", 0, 0, FULL_HELP_OPT},
      {"usage", 0, 0, USAGE_OPT},
      {"version", 0, 0, 'V'},
      {0, 0, 0, 0}
    };
    static const char *short_options = "hVm:s:t:o:c:Cp:rqL:U:wu";

    std::string err;
#define CHECK_ERR(type,val,which) if(!err.empty()) { std::cerr << "Invalid " #type " '" << val << "' for [" which "]: " << err << "\n"; exit(1); }
    while(true) { 
      int index = -1;
      int c = getopt_long(argc, argv, short_options, long_options, &index);
      if(c == -1) break;
      switch(c) {
      case ':': 
        std::cerr << "Missing required argument for "
                  << (index == -1 ? std::string(1, (char)optopt) : std::string(long_options[index].name))
                  << std::endl;
        exit(1);
      case 'h':
        std::cout << usage() << "\n\n" << help() << std::endl;
        exit(0);
      case USAGE_OPT:
        std::cout << usage() << "\nUse --help for more information." << std::endl;
        exit(0);
      case 'V':
        print_version();
        exit(0);
      case '?':
        std::cerr << "Use --usage or --help for some help\n";
        exit(1);
      case FULL_HELP_OPT:
        std::cout << usage() << "\n\n" << help() << "\n\n" << hidden() << std::endl;
        exit(0);
      case 'm':
        mer_len_given = true;
        mer_len_arg = yaggo::conv_uint<uint32_t>((const char *)optarg, err, false);
        CHECK_ERR(uint32_t, optarg, "-m, --mer-len=uint32")
        break;
      case 's':
        size_given = true;
        size_arg = yaggo::conv_uint<uint64_t>((const char *)optarg, err, true);
        CHECK_ERR(uint64_t, optarg, "-s, --size=uint64")
        break;
      case 't':
        threads_given = true;
        threads_arg = yaggo::conv_uint<uint32_t>((const char *)optarg, err, false);
        CHECK_ERR(uint32_t, optarg, "-t, --threads=uint32")
        break;
      case 'o':
        output_given = true;
        output_arg.assign(optarg);
        break;
      case 'c':
        counter_len_given = true;
        counter_len_arg = yaggo::conv_uint<uint32_t>((const char *)optarg, err, false);
        CHECK_ERR(uint32_t, optarg, "-c, --counter-len=Length in bits")
        break;
      case OUT_COUNTER_LEN_OPT:
        out_counter_len_given = true;
        out_counter_len_arg = yaggo::conv_uint<uint32_t>((const char *)optarg, err, false);
        CHECK_ERR(uint32_t, optarg, "    --out-counter-len=Length in bytes")
        break;
      case 'C':
        both_strands_flag = true;
        break;
      case 'p':
        reprobes_given = true;
        reprobes_arg = yaggo::conv_uint<uint32_t>((const char *)optarg, err, false);
        CHECK_ERR(uint32_t, optarg, "-p, --reprobes=uint32")
        break;
      case 'r':
        raw_flag = true;
        break;
      case BOTH_OPT:
        both_flag = true;
        break;
      case 'q':
        quake_flag = true;
        break;
      case QUALITY_START_OPT:
        quality_start_given = true;
        quality_start_arg = yaggo::conv_uint<uint32_t>((const char *)optarg, err, false);
        CHECK_ERR(uint32_t, optarg, "    --quality-start=uint32")
        break;
      case MIN_QUALITY_OPT:
        min_quality_given = true;
        min_quality_arg = yaggo::conv_uint<uint32_t>((const char *)optarg, err, false);
        CHECK_ERR(uint32_t, optarg, "    --min-quality=uint32")
        break;
      case 'L':
        lower_count_given = true;
        lower_count_arg = yaggo::conv_uint<uint64_t>((const char *)optarg, err, false);
        CHECK_ERR(uint64_t, optarg, "-L, --lower-count=uint64")
        break;
      case 'U':
        upper_count_given = true;
        upper_count_arg = yaggo::conv_uint<uint64_t>((const char *)optarg, err, false);
        CHECK_ERR(uint64_t, optarg, "-U, --upper-count=uint64")
        break;
      case MATRIX_OPT:
        matrix_given = true;
        matrix_arg.assign(optarg);
        break;
      case TIMING_OPT:
        timing_given = true;
        timing_arg = optarg;
        break;
      case STATS_OPT:
        stats_given = true;
        stats_arg = optarg;
        break;
      case 'w':
        no_write_flag = true;
        break;
      case 'u':
        measure_flag = true;
        break;
      case BUFFERS_OPT:
        buffers_given = true;
        buffers_arg = yaggo::conv_uint<uint64_t>((const char *)optarg, err, false);
        CHECK_ERR(uint64_t, optarg, "    --buffers=uint64")
        break;
      case BUFFER_SIZE_OPT:
        buffer_size_given = true;
        buffer_size_arg = yaggo::conv_uint<uint64_t>((const char *)optarg, err, false);
        CHECK_ERR(uint64_t, optarg, "    --buffer-size=uint64")
        break;
      case OUT_BUFFER_SIZE_OPT:
        out_buffer_size_given = true;
        out_buffer_size_arg = yaggo::conv_uint<uint64_t>((const char *)optarg, err, false);
        CHECK_ERR(uint64_t, optarg, "    --out-buffer-size=uint64")
        break;
      case LOCK_OPT:
        lock_flag = true;
        break;
      case STREAM_OPT:
        stream_flag = true;
        break;
      }
    }
    if(!mer_len_given)
      error("[-m, --mer-len=uint32] required switch");
    if(!size_given)
      error("[-s, --size=uint64] required switch");
    if(argc - optind < 0)
      error("Requires at least 0 argument.");
    for( ; optind < argc; ++optind) {
      file_arg.push_back(argv[optind]);
    }
  }
#define count_args_USAGE "Usage: jellyfish count [options] file:path+"
  const char * usage() const { return count_args_USAGE; }
  void error(const char *msg) { 
    std::cerr << "Error: " << msg << "\n" << usage()
              << "\nUse --help for more information"
              << std::endl;
    exit(1);
  }
#define count_args_HELP "Count k-mers or qmers in fasta or fastq files\n\n" \
  "Options (default value in (), *required):\n" \
  " -m, --mer-len=uint32                    *Length of mer\n" \
  " -s, --size=uint64                       *Hash size\n" \
  " -t, --threads=uint32                     Number of threads (1)\n" \
  " -o, --output=string                      Output prefix (mer_counts)\n" \
  " -c, --counter-len=Length in bits         Length of counting field (7)\n" \
  "     --out-counter-len=Length in bytes    Length of counter field in output (4)\n" \
  " -C, --both-strands                       Count both strand, canonical representation (false)\n" \
  " -p, --reprobes=uint32                    Maximum number of reprobes (62)\n" \
  " -r, --raw                                Write raw database (false)\n" \
  " -q, --quake                              Quake compatibility mode (false)\n" \
  "     --quality-start=uint32               Starting ASCII for quality values (64)\n" \
  "     --min-quality=uint32                 Minimum quality. A base with lesser quality becomes an N (0)\n" \
  " -L, --lower-count=uint64                 Don't output k-mer with count < lower-count\n" \
  " -U, --upper-count=uint64                 Don't output k-mer with count > upper-count\n" \
  "     --matrix=Matrix file                 Hash function binary matrix\n" \
  "     --timing=Timing file                 Print timing information\n" \
  "     --stats=Stats file                   Print stats\n" \
  "     --usage                              Usage\n" \
  " -h, --help                               This message\n" \
  "     --full-help                          Detailed help\n" \
  " -V, --version                            Version"

  const char * help() const { return count_args_HELP; }
#define count_args_HIDDEN "Hidden options:\n" \
  "     --both                               Write list and raw database (false)\n" \
  " -w, --no-write                           Don't write database (false)\n" \
  " -u, --measure                            Write usage statistics (false)\n" \
  "     --buffers=uint64                     Number of buffers per thread\n" \
  "     --buffer-size=uint64                 Size of buffers (8192)\n" \
  "     --out-buffer-size=uint64             Size of output buffer per thread (20000000)\n" \
  "     --lock                               Lock hash in memory (no swapping) (false)\n" \
  "     --stream                             Read from stream, not memory map (false)"

  const char * hidden() const { return count_args_HIDDEN; }
  void print_version(std::ostream &os = std::cout) const {
#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION "0.0.0"
#endif
    os << PACKAGE_VERSION << "\n";
  }
  void dump(std::ostream &os = std::cout) {
    os << "mer_len_given:" << mer_len_given << " mer_len_arg:" << mer_len_arg << "\n";
    os << "size_given:" << size_given << " size_arg:" << size_arg << "\n";
    os << "threads_given:" << threads_given << " threads_arg:" << threads_arg << "\n";
    os << "output_given:" << output_given << " output_arg:" << output_arg << "\n";
    os << "counter_len_given:" << counter_len_given << " counter_len_arg:" << counter_len_arg << "\n";
    os << "out_counter_len_given:" << out_counter_len_given << " out_counter_len_arg:" << out_counter_len_arg << "\n";
    os << "both_strands_flag:" << both_strands_flag << "\n";
    os << "reprobes_given:" << reprobes_given << " reprobes_arg:" << reprobes_arg << "\n";
    os << "raw_flag:" << raw_flag << "\n";
    os << "both_flag:" << both_flag << "\n";
    os << "quake_flag:" << quake_flag << "\n";
    os << "quality_start_given:" << quality_start_given << " quality_start_arg:" << quality_start_arg << "\n";
    os << "min_quality_given:" << min_quality_given << " min_quality_arg:" << min_quality_arg << "\n";
    os << "lower_count_given:" << lower_count_given << " lower_count_arg:" << lower_count_arg << "\n";
    os << "upper_count_given:" << upper_count_given << " upper_count_arg:" << upper_count_arg << "\n";
    os << "matrix_given:" << matrix_given << " matrix_arg:" << matrix_arg << "\n";
    os << "timing_given:" << timing_given << " timing_arg:" << timing_arg << "\n";
    os << "stats_given:" << stats_given << " stats_arg:" << stats_arg << "\n";
    os << "no_write_flag:" << no_write_flag << "\n";
    os << "measure_flag:" << measure_flag << "\n";
    os << "buffers_given:" << buffers_given << " buffers_arg:" << buffers_arg << "\n";
    os << "buffer_size_given:" << buffer_size_given << " buffer_size_arg:" << buffer_size_arg << "\n";
    os << "out_buffer_size_given:" << out_buffer_size_given << " out_buffer_size_arg:" << out_buffer_size_arg << "\n";
    os << "lock_flag:" << lock_flag << "\n";
    os << "stream_flag:" << stream_flag << "\n";
    os << "file_arg:" << yaggo::vec_str(file_arg) << "\n";
  }
private:
};

#endif // __COUNT_ARGS_HPP__"
