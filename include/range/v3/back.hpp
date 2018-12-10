/// \file
// Range v3 library
//
//  Copyright Eric Niebler 2014-present
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// Project home: https://github.com/ericniebler/range-v3
//

#ifndef RANGES_V3_BACK_HPP
#define RANGES_V3_BACK_HPP

#include <range/v3/range_fwd.hpp>
#include <range/v3/begin_end.hpp>
#include <range/v3/range_concepts.hpp>
#include <range/v3/range_traits.hpp>
#include <range/v3/utility/iterator.hpp>
#include <range/v3/utility/static_const.hpp>

namespace ranges
{
    inline namespace v3
    {
        /// \ingroup group-core
        struct back_fn
        {
            /// \return `*prev(end(rng))`
            CPP_template(typename Rng)(
                requires CommonRange<Rng> && BidirectionalRange<Rng>)
            constexpr /*c++14*/
            range_reference_t<Rng> operator()(Rng &&rng) const
            {
                return *prev(end(rng));
            }
        };

        /// \ingroup group-core
        /// \sa `back_fn`
        RANGES_INLINE_VARIABLE(back_fn, back)
    }
}

#endif
