CC     = gcc -std=c11 -g
CFLAGS = -Wall
LFLAGS =

PROG = escalona
OBJS = graphUtils.o \
		seriabilityUtils.o \
		transactionUtils.o \
		$(PROG).o

.PHONY: limpa faxina clean distclean purge all

%.o: %.c %.h
	$(CC) -c $(CFLAGS) $<

$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

docs: Doxyfile
	doxygen $<

Doxyfile:
	doxygen -g
	sed -e "s;OPTIMIZE_OUTPUT_FOR_C *= *.*;OPTIMIZE_OUTPUT_FOR_C = YES;g" $@ >$@.new
	sed -e "s;EXTRACT_ALL *= *.*;EXTRACT_ALL = YES;g" $@.new >$@
	sed -e "s;EXTRACT_PRIVATE *= *.*;EXTRACT_PRIVATE = YES;g" $@ >$@.new
	sed -e "s;EXTRACT_STATIC *= *.*;EXTRACT_STATIC = YES;g" $@.new >$@
	sed -e "s;EXTRACT_LOCAL_METHODS *= *.*;EXTRACT_LOCAL_METHODS = YES;g" $@ >$@.new
	sed -e "s;GENERATE_LATEX *= *.*;GENERATE_LATEX = NO;g" $@.new >$@
	sed -e "s;SOURCE_BROWSE *= *.*;SOURCE_BROWSE = YES;g" $@ >$@.new
	sed -e "s;VERBATIM_HEADER *= *.*;VERBATIM_HEADER = YES;g" $@.new >$@
	rm -f $@.new

clean:
	@rm -f *~

purge:   clean
	@rm -f *.o core a.out
	@rm -f $(PROG)