Figure 10.8  Sequence of Events for Trace of reverse_input_words(3)
Call reverse_input_words with n equal to 3.
       Scan the first word ("bits") into word.
       Call reverse_input_words with n equal to 2.
              Scan the second word ("and") into word.
              Call reverse_input_words with n equal to 1.
                     Scan the third word ("bytes") into word.
                     Display the third word ("bytes").
                     Return from third call.
              Display the second word ("and").
              Return from second call.
       Display the first word ("bits").
       Return from original call.